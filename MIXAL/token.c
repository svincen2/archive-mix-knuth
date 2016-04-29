/*
* token.c
* Provides definitions for functions declared in token.h.
*/
#include "token.h"


/*
* Clear the lexeme to all 0s.
* param lexeme - Lexeme to be cleared.
*/
void clear_lexeme(char lexeme[MAX_LEXEME_SIZE])
{
    int i;
    for(i = 0; i < MAX_LEXEME_SIZE; ++i)
    {
        lexeme[i] = 0;
    }
}


/*
* Initialize the given token to NONE, and clear the lexeme.
* param tk - Token to clear.
*/
void token_init(token_pt tk)
{
    tk->type = NONE;
    clear_lexeme(tk->lexeme);
}
