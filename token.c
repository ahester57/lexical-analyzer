#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "token.h"
#include "states.h"

// I know these first few aren't actually tokens.
// Just so the indices match with enum STATE
const char* TOKENS[] = {
    "errorTK",
    "initialTK",
    "s1TK",
    "s2TK",
    "opTK",
    "delimTK",
    "idTK",
    "intTK",
    "=TK",
    ">TK",
    "<TK",
    ":TK",
    "+TK",
    "-TK",
    "*TK",
    "/TK",
    "%TK",
    ".TK",
    "(TK",
    ")TK",
    ",TK",
    "{TK",
    "}TK",
    ";TK",
    "[TK",
    "]TK",
    "&TK",
    "EOFTK"
};

const char*
gettoken(const enum STATE state)
{
    return TOKENS[state];
}

int
isEOFtoken(const token_t* token)
{
    if (strcmp(token->id, "EOFTK") == 0)
        return 1;
    return 0;
}

void
maketoken(token_t* token,
          const enum STATE state,
          char* string,
          const int line)
{
    token->instance = (char*) malloc(32*sizeof(char));
    strcpy(token->instance, string);
    token->id = gettoken(state);
    token->line_num = line;
}

void
copytoken(token_t* dest, const token_t* src)
{
    dest = (token_t*) malloc(sizeof(token_t));
    dest->instance = (char*) malloc(32*sizeof(char));
    strcpy(dest->instance, src->instance);
    dest->id = src->id;
    dest->line_num = src->line_num;
}