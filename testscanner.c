#include <stdlib.h>
#include <stdio.h>
#include "testscanner.h"
#include "scanner.h"
#include "token.h"

token_t*
testscanner(FILE* fp)
{
    return scanner(fp);
}