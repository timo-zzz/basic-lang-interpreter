#include "common.h"
#include "scanner.h"

void printToken(Token token) {
    // there HAS to be a better way to do this
    switch (token.type) {
        case TOKEN_LET: printf("TOKEN_LET\n");
        case TOKEN_PRINT: printf("TOKEN_PRINT\n");
        case TOKEN_END: printf("TOKEN_END\n");
        case TOKEN_GOTO: printf("TOKEN_GOTO\n");
        case TOKEN_IF: printf("TOKEN_IF\n");
        case TOKEN_FOR: printf("TOKEN_FOR\n");
        case TOKEN_NEXT: printf("TOKEN_NEXT\n");
        case TOKEN_RETURN: printf("TOKEN_RETURN\n");
        case TOKEN_DEF: printf("TOKEN_DEF\n");
        case TOKEN_REM: printf("TOKEN_REM\n");
        
        case TOKEN_NUMBER: printf("TOKEN_NUMBER\n");
        case TOKEN_STRING: printf("TOKEN_STRING\n");

        case TOKEN_PLUS: printf("TOKEN_PLUS\n");
        case TOKEN_MINUS: printf("TOKEN_MINUS\n");
        case TOKEN_STAR: printf("TOKEN_STAR\n");
        case TOKEN_SLASH: printf("TOKEN_SLASH\n");
        case TOKEN_CARET: printf("TOKEN_CARET\n");
        case TOKEN_LEFT_PAREN: printf("TOKEN_LEFT_PAREN\n");
        case TOKEN_RIGHT_PAREN: printf("TOKEN_RIGHT_PAREN\n");

        case TOKEN_NEWLINE: printf("TOKEN_NEWLINE\n");
        case TOKEN_ERROR: printf("TOKEN_ERROR\n");
        case TOKEN_IDENTIFIER: printf("TOKEN_IDENTIFIER\n");
    }
}