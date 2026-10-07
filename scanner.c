#include "scanner.h"

typedef struct {
    const char* start; // Source code char array
    const char* current; 
    int line; // For reporting errors n stuff
} Scanner;

Scanner scanner;

void initScanner(const char* source) {
    scanner.start = source;
    scanner.current = source;
    scanner.line = 1;
}

static Token makeToken(TokenType type) {
    Token token;
    token.type = type;
    return token;
}

// Moves onto the next character and returns the current one
static char advance() {
    scanner.current++;
    return scanner.current[-1];
}

// Shows the next character without advancing
static char peek() {
    return *scanner.current;
}

Token scan() { // const so we can only read and don't do weird stuff
    // switch ()
}