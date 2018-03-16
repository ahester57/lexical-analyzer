#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "alphabet.h"
#include "find.h"

static const char ops[] = "=><:+-*/%";
static const char delims[] = ".(),{};[]&";

int
isinalphabet(const char c)
{
    if (isalnum(c) || findchar(c, ops) ||
        findchar(c, delims)) { 
        return 1;
    }
    return 0;
}

int
isletter(const char c)
{
    if (isalpha(c))
        return 1;
    return 0;
}

int
isnumber(const char c)
{
    if (isdigit(c))
        return 1;
    return 0;
}

int
isoperator(const char c)
{
    if (findchar(c, ops))
        return 1;
    return 0;
}

int
isdelim(const char c)
{
    if (findchar(c, delims))
        return 1;
    return 0;
}