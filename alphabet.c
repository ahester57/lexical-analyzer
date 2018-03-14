#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "alphabet.h"
#include "find.h"

static char ops[] = "=><:+-*/%";
static char delims[] = ".(),{};[]&";

int
isinalphabet(char c)
{
    if (isalnum(c) || find(c, ops) || find(c, delims))
        return 1;
    return 0;
}