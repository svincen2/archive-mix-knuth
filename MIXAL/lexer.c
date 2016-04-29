/*
* lexer.c
*/
#include "token.h"
#include <ctype.h>
#include <stdio.h>


/* Next character to process when building a token. */
char next_char = 0;

/* Forward declarations. */
void skip_ws(FILE*);
void get_next_char(token_pt, FILE*);
void get_next_token(token_pt, FILE*);
void determine_token(token_pt, FILE*);
void identifier(token_pt, FILE*);
void number(token_pt, FILE*);
void operator(token_pt);


/*
* NOT YET IMPLEMENTED
*/
int is_opcode(token_pt tk)
{
    return 0;
}

/*
* Processes the input file and fills tk with the next token.
* If a token was successfully created, 1 is returned,
* otherwise 0 is returned.
* param tk - Token pointer.
* param input - Input file.
*/
void next_token(token_pt tk, FILE* input)
{
    token_init(tk);
    skip_ws(input);
    if(feof(input))
    {
        tk->type = EOF;
        return;
    }
    // Get the next character.
    get_next_char(tk, input);

    // Get the next token.
    get_next_token(tk, input);
}

/*
* Skip over whitespace characters.
* param input - Input file.
*/
void skip_ws(FILE* input)
{
    if(next_char && !isspace(next_char)) return;
    while((next_char = fgetc(input)) != EOF && isspace(next_char))
        ;
}

/*
* Get the next character.
*/
void get_next_char(token_pt tk, FILE* input)
{
    if(next_char) tk->lexeme[0] = next_char;
    else tk->lexeme[0] = fgetc(input);
}

/*
* Get the next token from the input file.
* param tk - Token pointer.
* param input - Input file.
*/
void get_next_token(token_pt tk, FILE* input)
{
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

/*
* Process an identifier from the given input file stream.
* An identifier is any string of alphabetic characters [a-z, A-Z].
* param tk - Token pointer.
* param input - Input file.
*/
void identifier(token_pt tk, FILE* input)
{
    int i = 1;       // Index of next char to fill in lexeme.
    do
    {
        next_char = fgetc(input);
        if(isalpha(next_char))
            tk->lexeme[i++] = next_char;
    }
    while(isalpha(next_char));
    tk->type = ID;
}

/*
* Read a number token from the input stream.
* param tk - Current working token.
* param input - Input file stream to read from.
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
* param tk - Token pointer.
*/
void operator(token_pt tk)
{
    switch(tk->lexeme[0])
    {
    case ',': tk->type = COMMA; break;
    case '(': tk->type = LEFT_PAREN; break;
    case ')': tk->type = RIGHT_PAREN; break;
    case ':': tk->type = COLON; break;
    case '*': tk->type = ASTERISK; break;
    default: tk->type = BAD;
    }
    next_char = 0;
}

