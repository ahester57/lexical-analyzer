#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "fsadriver.h"
#include "alphabet.h"
#include "wordlist.h"
#include "token.h"
#include "states.h"


token_t*
scanner(const wordlist_t* filter)
{
    token_t* tk = (token_t*) malloc(sizeof(token_t));
    tk = fsadriver(filter);

    printf("%s, %s, %d\n", tk->id, tk->instance, tk->line_num);
    return tk;
}
