#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "alphabet.h"
#include "find.h"

static const char ops[] = "=><:+-*/%";
static const char delims[] = ".(),{};[]&";

int
isinalphabet(char c)
{
    if (isalnum(c) || findchar(c, ops) || findchar(c, delims))
        return 1;
    return 0;
}