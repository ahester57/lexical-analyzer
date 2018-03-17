#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fsadriver.h"
#include "fsatable.h"
#include "wordlist.h"
#include "token.h"
#include "states.h"


token_t*
fsadriver(const wordlist_t* filter)
{
    int i = 0;
    enum STATE state = INITIAL;
    enum STATE nextstate = ERROR;
    token_t* token = (token_t*) malloc(sizeof(token_t));
    char nextchar;
    char* string;
    char buf[64];

    nextchar = buf[i];
    while (state < 100)
    {
        nextstate = fsatable(state, nextchar);

        // If there is an error
        if (nextstate == ERROR) {
            fprintf(stderr, "Error while parsing @ line ");
            fprintf(stderr, "%d\n", 69);
            return (token_t*)NULL;
        }
        // If we have reached a final state
        if (nextstate >= IDENTIFIER) {
                if (nextstate == 100) {
                    strcpy(token->instance, buf);
                    token->id = "IDENTIFIER";
                }
        } else {
            state = nextstate;
            buf[i] = nextchar;
            i++;
            nextchar = buf[i];
        }
    }
    return (token_t*)NULL;
}

