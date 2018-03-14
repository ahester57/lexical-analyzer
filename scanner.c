#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "alphabet.h"
#include "token.h"

token_t*
scanner(FILE* fp)
{
    token_t* token = (token_t*) malloc(sizeof(token_t));
    token->id = "idtk";
    token->instance = "instance";
    token->line_num = 5;
    return token;
}