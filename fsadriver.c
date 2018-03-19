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
        //fprintf(stderr, "line = %s\n", filter->list[line]);
        if (filter->list[line] == (char*)NULL) {
            token->id = gettoken(EOFILE);
            token->instance = "EOF";
            token->line_num = line;
            return token;
        } 
        strcpy(buf, filter->list[line]);
        // first for loop for each line

        nextchar = buf[column];
        while (state < IDENTIFIER)
        {
/*              if (nextchar == '\0') {
                column = 0;
                //break;
            }  */
            nextstate = fsatable(state, nextchar);
            fprintf(stderr, "state = %d\n", state);
            fprintf(stderr, "string = %s\n", string);
            fprintf(stderr, "next = %c\n", nextchar);

            // If there is an error
            if (nextstate == ERROR) {
                fprintf(stderr, "Error while parsing @ line ");
                fprintf(stderr, "%d\n", line);
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
                nextchar = buf[column];
                if (nextchar == '\0') {
                    column = 0;
                    line++;
                    //break;
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
/*                 if (nextchar == '\0') {
                    column = 0;
                    break;
                } */
            }
        }
    }
    token->id = gettoken(EOFILE);
    token->instance = "EOF";
    token->line_num = line;
    return token;
}

