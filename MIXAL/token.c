/*
* token.c
*/
#include "token.h"


// Initialize a token.
void token_init(token_pt tk)
{
    tk->type = NONE;
    clear_lexeme(tk->lexeme);
}


// Clear a lexeme to all 0s.
void clear_lexeme(char lexeme[MAX_LEXEME_SIZE])
{
    int i;
    for(i = 0; i < MAX_LEXEME_SIZE; ++i)
    {
        lexeme[i] = 0;
    }
}
