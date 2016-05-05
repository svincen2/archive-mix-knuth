#include <stdio.h>
#include "lexer.h"
#include "token.h"


int main()
{
    FILE* in = fopen("TEST.txt", "r");
    token next;
    token_init(&next);
    while(next.type != EOF)
    {
        next_token(&next, in);
        if(next.type == EOF) break;
        printf("Type: %d, ", next.type);
        printf("Lexeme: \"%s\"\n", next.lexeme);
    }
}