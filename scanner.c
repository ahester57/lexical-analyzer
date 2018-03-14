#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "alphabet.h"
#include "wordlist.h"
#include "token.h"

static int line = 0;
static int column = 0;

token_t*
scanner(wordlist_t* filter)
{
    token_t* token = (token_t*) malloc(sizeof(token_t));
    token->id = "idtk";
    token->instance = "instance";
    token->line_num = 5;
    token->id = NULL;
    while (token->id == NULL)
    {
        // do FSA tables stuff
        token->id = "id_tk"; 
    }
    return token;
}