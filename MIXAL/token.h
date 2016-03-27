/*
* token.h
* Tokens produced by the MIX lexer.
*/


// Type of token, one of: OP, NUM
enum token_type
{
    OP, NUM
};


// A token produced by MIX lexer.
typedef struct _token
{
    token_type type;
} token, *token_pt;
