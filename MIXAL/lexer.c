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
    while((next_char = fgetc(input)) != EOF && isspace(next_char));
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
        if(next_char != EOF && !isspace(next_char))
            tk->lexeme[i++] = next_char;
    }
    while(!(next_char == EOF || isspace(next_char)));
    tk->type = NUM;
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
    if(feof(input)) tk->type = END;
    else
    {
        // Get the next character.
        if(next_char) tk->lexeme[0] = next_char;
        else tk->lexeme[0] = fgetc(input);
        
        // Decide what to do next.
        if(isalpha(tk->lexeme[0]))
        {
            // Possibly an OP or an ID.
        }
        else if(isdigit(tk->lexeme[0])
                || tk->lexeme[0] == '+'
                || tk->lexeme[0] == '-')
        {
            // Only possibility is a NUM token.
            number(tk, input);
        }
        else tk->type = BAD;
    }
}
