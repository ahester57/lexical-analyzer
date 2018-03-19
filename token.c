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