#include <stdlib.h>
#include <stdio.h>
#include "testscanner.h"
#include "scanner.h"
#include "wordlist.h"
#include "token.h"

token_t*
testscanner(wordlist_t* filter)
{
    return scanner(filter);
    fprintf(stderr, "%c\n", 'c');
}