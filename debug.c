#include "common.h"
#include "debug.h"

void printToken(Token token) {
    // there HAS to be a better way to do this
    switch (token.type) {
        case TOKEN_LET: printf("TOKEN_LET\n"); break;
        case TOKEN_PRINT: printf("TOKEN_PRINT\n"); break;
        case TOKEN_END: printf("TOKEN_END\n"); break;
        case TOKEN_GOTO: printf("TOKEN_GOTO\n"); break;
        case TOKEN_IF: printf("TOKEN_IF\n"); break;
        case TOKEN_FOR: printf("TOKEN_FOR\n"); break;
        case TOKEN_NEXT: printf("TOKEN_NEXT\n"); break;
        case TOKEN_RETURN: printf("TOKEN_RETURN\n"); break;
        case TOKEN_DEF: printf("TOKEN_DEF\n"); break;
        case TOKEN_REM: printf("TOKEN_REM\n"); break;
        
        case TOKEN_NUMBER: printf("TOKEN_NUMBER\n"); break;
        case TOKEN_STRING: printf("TOKEN_STRING\n"); break;

        case TOKEN_PLUS: printf("TOKEN_PLUS\n"); break;
        case TOKEN_MINUS: printf("TOKEN_MINUS\n"); break;
        case TOKEN_STAR: printf("TOKEN_STAR\n"); break;
        case TOKEN_SLASH: printf("TOKEN_SLASH\n"); break;
        case TOKEN_CARET: printf("TOKEN_CARET\n"); break;
        case TOKEN_LEFT_PAREN: printf("TOKEN_LEFT_PAREN\n"); break;
        case TOKEN_RIGHT_PAREN: printf("TOKEN_RIGHT_PAREN\n"); break;

        case TOKEN_NEWLINE: printf("TOKEN_NEWLINE\n"); break;
        case TOKEN_ERROR: printf("TOKEN_ERROR\n"); break;
        case TOKEN_IDENTIFIER: printf("TOKEN_IDENTIFIER\n"); break;
        default: printf("No token :( \n"); break;
    }
}