#ifndef basic_scanner_h
#define basic_scanner_h

typedef enum {
    // Keywords
    TOKEN_DEF, TOKEN_END, TOKEN_FOR, TOKEN_GOTO, TOKEN_IF, TOKEN_LET, TOKEN_NEXT, TOKEN_PRINT, TOKEN_REM, TOKEN_RETURN,

    // Literals
    TOKEN_NUMBER, TOKEN_STRING,

    // Math operators and parentheses
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_STAR, TOKEN_SLASH, TOKEN_CARET, TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,

    // Misc. BASIC relies on newlines to end statements
    TOKEN_NEWLINE, TOKEN_ERROR, TOKEN_IDENTIFIER, TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;

    // Lexeme data
    char* start; // Pointer to start of lexeme in the source code
    int length; // Length of lexeme for indexing
} Token;

void initScanner(const char* source);
Token scan();

#endif