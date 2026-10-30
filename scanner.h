#ifndef basic_scanner_h
#define basic_scanner_h

typedef enum {
    // Keywords
    TOKEN_LET, TOKEN_PRINT, TOKEN_END, TOKEN_GOTO, TOKEN_IF, TOKEN_FOR, TOKEN_NEXT, TOKEN_RETURN, TOKEN_DEF, TOKEN_REM,

    // Literals
    TOKEN_NUMBER, TOKEN_STRING,

    // Math operators and parentheses
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_STAR, TOKEN_SLASH, TOKEN_CARET, TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,

    // Misc. BASIC relies on newlines to end statements
    TOKEN_NEWLINE, TOKEN_ERROR, TOKEN_IDENTIFIER
} TokenType;

typedef struct {
    TokenType type;

    // Lexeme data
    char* start; // Pointer to start of lexeme in the source code
    int length; // Length of lexeme for indexing
} Token;

Token scan();

#endif