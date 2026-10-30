#include <stdio.h>

#include "common.h"
#include "scanner.h"

static char* readFile(const char* filePath) {
    FILE* file;

    // Open file in rb to prevent newline translations (translating "\r\n" to "\n" on Windows) so our character count is right
    file = fopen(filePath, "rb");
    if (file == NULL) {
        perror("No file exists at this path");
        return 2;
    }

    // Get the file size. We use fseeko, ftello, and off_t instead of fseek, ftell, and long/size_t since those methods return
    // a long, a long is signed but too small, and size_t is unsigned so we can't see some errors
    fseeko(file, 0L, SEEK_END); // Go to end of file
    off_t fileSize = ftello(file); // Get numeric file position (# offset from start)
    rewind(file); // Move file pointer back to start of file

    char* buffer = (char*)malloc(fileSize + 1); // +1 for null terminator
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 2;
    }

    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    
    // Add null terminator
    buffer[bytesRead] = '\0';

    fclose(file);
    return buffer;
}

// arg c is arg count
int main(int argc, char* argv[]) {
    char* text = readFile(argv[1]); // First argument (idx 0) in argv is name of exe being run

    int i = 0;
    while (text[i] != '\0') {
        Token token = scan();
        printToken(token);
    }
    return 0;
} 