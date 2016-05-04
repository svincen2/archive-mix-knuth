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
void alpha_num(token_pt, FILE*);
void number(token_pt, FILE*);
void operator(token_pt);


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
* param tk - Token pointer.
* param input - Input file.
*/
void get_next_char(token_pt tk, FILE* input)
{
    // Leftover character, use it.
    if(next_char) tk->lexeme[0] = next_char;

    // No leftover char, read next from input.
    else tk->lexeme[0] = fgetc(input);
}

/*
* Get the next token from the input file.
* The first character has already been read.
* The value of first character determines how
* to evaluate further.
* param tk - Token pointer.
* param input - Input file.
*/
void get_next_token(token_pt tk, FILE* input)
{
    if(isalnum(tk->lexeme[0]))
    {
        // An alpha numeric token.
        alpha_num(tk, input);
    }
    else if(tk->lexeme[0] == '+' || tk->lexeme[0] == '-')
    {
        // Only possibility is a number.
        number(tk, input);
    }
    // Only possibility is an operator.
    else operator(tk);
}

/*
* Read an alhpa-numeric token from input stream.
* While reading, determines if the token is strictly
* alphabetic, strictly a number, or a combination.
* param tk - Token pointer.
* param input - Input file.
*/
void alpha_num(token_pt tk, FILE* input)
{
    // First char was either alphabetic or a digit.
    token_type tt = isalpha(next_char)? ALPHA : NUM;
    int i = 0;
    do
    {
        next_char = fgetc(input);

        // Skip remaining chars if too large for buffer.
        if(++i >= MAX_LEXEME_SIZE) continue;

        // Add alpha-numeric character to lexeme.
        if(next_char != EOF && isalnum(next_char))
            tk->lexeme[i] = next_char;

        if(isalpha(next_char) && tt == NUM) tt = ALPHA_NUM;
        else if(isdigit(next_char) && tt == ALPHA) tt = ALPHA_NUM;
    }
    while(next_char != EOF && isalnum(next_char));
    tk->type = tt;
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
    case ',': 
    case '(':
    case ')':
    case ':':
    case '*':
        tk->type = OP;
        break;
    default:
        tk->type = BAD;
    }
    next_char = 0;
}

