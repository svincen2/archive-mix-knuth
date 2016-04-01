/*
* lexer.c
*/
#include "token.h"
#include <ctype.h>
#include <stdio.h>


/* Next character to process when building a token. */
char next_char = 0;


/*
* Skip over whitespace characters.
*/
void skip_ws(FILE* input)
{
    if(next_char && !isspace(next_char)) return;
    while((next_char = fgetc(input)) != EOF && isspace(next_char))
        ;
}


/*
* Process an identifier from the given input file stream.
* An identifier is any string of alphabetic characters [a-z, A-Z].
*/
void identifier(token_pt tk, FILE* input)
{
    int i = 1;       // Index of next char to fill in lexeme.
    do
    {
        next_char = fgetc(input);
        if(isalpha(next_char)) tk->lexeme[i++] = next_char;
    }
    while(isalpha(next_char));
    tk->type = ID;
}


/*
* NOT YET IMPLEMENTED
*/
int is_opcode(token_pt tk)
{
    return 0;
}


/*
* Read a number token from the input stream.
* Param tk - Current working token.
* Param input - Input file stream to read from.
*/
void number(token_pt tk, FILE* input)
{
    int i = 1;      // Index of next char to fill in lexeme.
    do
    {
        next_char = fgetc(input);
        if(next_char != EOF && isdigit(next_char))
            tk->lexeme[i++] = next_char;
    }
    while(next_char != EOF && isdigit(next_char));
    tk->type = NUM;
}


/*
* Examine the token to determine if it is a valid,
* single character operator, such as ':' or ','
* If it is not a valid operator, it is a bad token.
*/
void operator(token_pt tk)
{
    switch(tk->lexeme[0])
    {
    case ',': tk->type = COMMA; break;
    case '(': tk->type = LEFT_PAREN; break;
    case ')': tk->type = RIGHT_PAREN; break;
    case ':': tk->type = COLON; break;
    default: tk->type = BAD;
    }
    next_char = 0;
}


/*
* Processes the input file and fills tk with the next token.
* If a token was successfully created, 1 is returned,
* otherwise 0 is returned.
*/
void next_token(token_pt tk, FILE* input)
{
    token_init(tk);
    skip_ws(input);
    if(feof(input)) tk->type = EOF;
    else
    {
        // Get the next character.
        if(next_char) tk->lexeme[0] = next_char;
        else tk->lexeme[0] = fgetc(input);
        
        // Look at first char to determine possible tokens.
        if(isalpha(tk->lexeme[0]))
        {
            // Possibly an OP or an ID.
            identifier(tk, input);
            if(is_opcode(tk)) tk->type = OP;
        }
        else if(isdigit(tk->lexeme[0])
                || tk->lexeme[0] == '+'
                || tk->lexeme[0] == '-')
        {
            // Only possibility is a NUM token.
            number(tk, input);
        }
        // Token must be a valid operator, or it is a bad token.
        else operator(tk);
    }
}
