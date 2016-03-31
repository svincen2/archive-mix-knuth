#ifndef MIXAL_LEXER_H
#define MIXAL_LEXER_H

#include <stdio.h>
#include "token.h"

/* Forward facing functions. */

// Get the next token from the file.
void next_token(token_pt, FILE*);

#endif
