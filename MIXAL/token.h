/*
* token.h
* Tokens produced by the MIXAL lexer.
*/
#ifndef MIXAL_TOKEN_H
#define MIXAL_TOKEN_H


// Maximum size of a lexeme.
#define MAX_LEXEME_SIZE 128


// Type of token, one of: OP, NUM (or NONE if no token type exists).
typedef enum
{
    NONE, OP, NUM, ID, COMMA, LEFT_PAREN, RIGHT_PAREN, COLON, ASTERISK, BAD
} token_type;


// A token produced by MIXAL lexer.
typedef struct
{
    token_type type;
    char lexeme[MAX_LEXEME_SIZE];
} token, *token_pt;


// Functions for working with tokens.
void token_init(token_pt);

#endif
