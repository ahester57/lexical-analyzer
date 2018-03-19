#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fsadriver.h"
#include "fsatable.h"
#include "wordlist.h"
#include "token.h"
#include "states.h"

static int line = 0;
static int column = 0;

token_t*
fsadriver(const wordlist_t* filter)
{
    int i = 0;
    enum STATE state = INITIAL;
    enum STATE nextstate = ERROR;
    token_t* token = (token_t*) malloc(sizeof(token_t));
    char nextchar;
    char string[256] = "";

    int numlines = filter->length;
    char buf[256];
    for (line; line < numlines; line++) {
        strcpy(buf, filter->list[line]);
        // first for loop for each line

        nextchar = buf[column];

        while (state < IDENTIFIER && nextchar != '\0')
        {
            nextstate = fsatable(state, nextchar);
            fprintf(stderr, "state = %d\n", state);
            fprintf(stderr, "string = %s\n", string);

            // If there is an error
            if (nextstate == ERROR) {
                fprintf(stderr, "Error while parsing @ line ");
                fprintf(stderr, "%d\n", 69);
                return (token_t*)NULL;
            }
            // If we have reached a final state
            if (nextstate >= IDENTIFIER) {
                state = nextstate;
                // If we have a single character token, add the current char
                if (i == 0)
                    string[i] = nextchar;

                token->instance = (char*) malloc(32*sizeof(char));
                strcpy(token->instance, string);
                token->id = gettoken(state);
                token->instance = string;
                token->line_num = line;

                if (i < 1)
                    column++;
                if (nextchar == '\0') {
                    column = 0;
                    line++;
                }
                return token;
            // If we're still not done
            } else {
                state = nextstate;
                string[i] = nextchar;
                i++;
                column++;
                nextchar = buf[column];
                if (nextchar == '\0') {
                    column = 0;
                    break;
                }
            }
        }
    }
    return (token_t*)NULL;
}

