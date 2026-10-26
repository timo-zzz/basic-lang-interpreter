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

static Token makeToken(TokenType type) {
    Token token;
    token.type = type;
    token.start = scanner.current;
    token.length = scanner.current - token.start;

    // Next char! Since we're at the end of this token
    advance();

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

    // Consume closing quote
    advance();

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
    if (isWhitespace(peek())) {
        return true;
    }

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

Token scan() { 
    skipWhitespace();

    // Set the start of the scanner to the start of the next lexeme. Should be done after we skipWhitespace so we don't include whitespace in our lexeme.
    scanner.start = scanner.current;

    switch (*scanner.current) {
        case '{': return makeToken(TOKEN_LEFT_PAREN);
    }
}