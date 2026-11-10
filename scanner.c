#include "common.h"
#include "scanner.h"

typedef struct {
    const char* start; // Points to start of current lexeme
    const char* current; 
    int line; // For reporting errors n stuff
} Scanner;

Scanner scanner;

void initScanner(const char* source) { // const so we can only read and don't do weird stuff
    scanner.start = source;
    scanner.current = source;
    scanner.line = 1;
}

// Moves onto the next character and returns the current one
static char advance() {
    scanner.current++;
    printf("we advanced\n");
    return scanner.current[-1];
}

// Shows the next character without advancing
static char peek() {
    return *scanner.current;
}

static Token makeToken(TokenType type) {
    Token token;
    token.type = type;
    token.start = scanner.current;
    token.length = scanner.current - token.start;
    printf("token namde\n");

    // Next char! Since we're at the end of this token
    advance();

    // Advance past closing quote in string tokens
    if (type == TOKEN_STRING) {
        advance();
    }

    return token;
}

// Tells us if a char is whitespace or not
static bool isWhitespace(char car) {
    return car == ' ' || car == '   ';
}

// Scans a string literal and returns its token. Should be called in the " case.
static Token string() {
    // Consume the opening quote
    advance();

    // Make sure the quote isn't a part of the lexeme
    scanner.start = scanner.current;

    // Consume characters until we hit the closing quote
    while (peek() != '"') {
        advance();
    }

    // We don't advance past the closing quote here because we don't want it to be part of the lexeme

    // mahybe add support for escape sequences later
    return makeToken(TOKEN_STRING);
}

// Returns true if the keyword is found and it doesn't continue, returns false 
static bool findKeyword(const char* lexeme, int len) {
    // Advance from the character we switched on
    advance();

    // iterate thru char* to see if it matches. if it continues, it an identifier
    for (int i = 1; i < len; i++) {
        if (peek() == lexeme[i]) {
            advance();
        } else {
            // Move the pointer back to the start of the lexeme if we didn't match the right keyword
            scanner.current -= i;
            return false;
        }
    }

    // Whitespace signifies the end of this token, so it doesn't continue and it is what we think it is
    if (isWhitespace(peek()) || peek() == '\0') { // 2nd condition ensures token at the end of a file isnt mistakenly marked as an identifier
        return true;
    }

    // Means its an identifier
    return false;

    // how to return right token?
       // return true or false and then 
        // if true return the right token in scan()  
        // if false move onto next keyword check or return TOKEN_IDENTIFIER in scan()
}

// Newlines are NOT whitespace in BASIC. Newlines end statements in BASIC.
static void skipWhitespace() {
    while (isWhitespace(peek())) {
        advance();
    }
}

static bool isAlpha(char car) {
    return (car >= 'a' && car <= 'b') ||
           (car >= 'A' && car <= 'B') ||
           car == '_';
}

static bool isDigit(char car) {
    return car >= '0' && car <= '9';
}

// Used to scan a number token
static Token number() {
    int decimalCount = 0; // Must not exceed 1
    while (isDigit(peek()) || peek() == '.') {
        // this is so inefficient
        if (peek() == '.') {
            decimalCount++;
            if (decimalCount > 1) {
                perror("More than 1 decimal in a number");
                exit(74);
            }
        }

        advance();
    }

    return makeToken(TOKEN_NUMBER);
}

static void identifier() {
    while (isAlpha(peek()) || isDigit(peek())) {
        advance();
    }
}

Token scan() { 
    printf("scan started\n");
    skipWhitespace();
    printf("whitespace skipped\n");

    // Set the start of the scanner to the start of the next lexeme. Should be done after we skipWhitespace so we don't include whitespace in our lexeme.
    scanner.start = scanner.current;
    printf("start = current\n");

    if (isDigit(peek())) return number();
    switch (*scanner.current) {
        printf("switch started\n");

        // Keywords/identifiers first!
        case 'D': {
            if (findKeyword("DEF", 3)) { return makeToken(TOKEN_DEF); }

            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }
        case 'E': {
            if (findKeyword("END", 3)) { return makeToken(TOKEN_END); }

            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }
        case 'F': {
            if (findKeyword("FOR", 3)) { return makeToken(TOKEN_FOR); }

            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }
        case 'G': {
            if (findKeyword("GOTO", 4)) { return makeToken(TOKEN_GOTO); }

            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }
        case 'I': {
            if (findKeyword("IF", 2)) { return makeToken(TOKEN_IF); }
            
            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }
        case 'L': {
            if (findKeyword("LET", 3)) { return makeToken(TOKEN_LET); }

            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }
        case 'N': {
            if (findKeyword("NEXT", 4)) { return makeToken(TOKEN_NEXT); }
        
            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }
        case 'P': {
            if (findKeyword("PRINT", 5)) { return makeToken(TOKEN_PRINT); }

            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }
        case 'R': {
            if (findKeyword("RETURN", 6)) { return makeToken(TOKEN_RETURN); }

            if (findKeyword("REM", 3)) { return makeToken(TOKEN_REM); }

            identifier();
            return makeToken(TOKEN_IDENTIFIER);
        }

        // Literals
        case '"': return string();

        // Operators and brackets
        case '+': return makeToken(TOKEN_PLUS);
        case '-': return makeToken(TOKEN_MINUS);
        case '*': return makeToken(TOKEN_STAR);
        case '/': return makeToken(TOKEN_SLASH);
        case '^': return makeToken(TOKEN_CARET);
        case '{': return makeToken(TOKEN_LEFT_PAREN); 
        case '}': return makeToken(TOKEN_RIGHT_PAREN);

        // Fun stuff
        case '\n': return makeToken(TOKEN_NEWLINE);
        case '\0': return makeToken(TOKEN_EOF);
        
        // Other identifiers
        default: {
            if (isAlpha(peek())) {
                identifier();
            }
        }
    }
}



