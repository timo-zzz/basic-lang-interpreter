typedef enum {
    // Keywords
    TOKEN_LET, TOKEN_PRINT, TOKEN_END, TOKEN_GOTO, TOKEN_IF, TOKEN_FOR, TOKEN_NEXT, TOKEN_RETURN, TOKEN_DEF, TOKEN_REM,

    // Literals
    TOKEN_NUMBER, TOKEN_STRING,

    // Math operators and parentheses
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_STAR, TOKEN_SLASH, TOKEN_CARET, TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,

    // Misc
    TOKEN_NEWLINE, TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
} Token;