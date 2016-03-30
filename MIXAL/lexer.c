/*
* lexer.c
*/
#include "token.h"
#include <stdio.h>

/*
* Processes the input file and fills tk with the next token.
* If a token was successfully created, 1 is returned,
* otherwise 0 is returned.
*/
int next_token(token_pt tk, FILE* input)
{
    if(feof(input)) return 0;   // No input left to process.
    
    return 1;
}
