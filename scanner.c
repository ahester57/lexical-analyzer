#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "fsadriver.h"
#include "alphabet.h"
#include "wordlist.h"
#include "token.h"

static int line = 0;
static int column = 0;

token_t*
scanner(const wordlist_t* filter)
{
    token_t* token;// = (token_t*) malloc(sizeof(token_t));
    token->instance = "instance";
    token->line_num = 5;
    token->id = NULL;
    while (token->id == NULL)
    {
        int i;
        int numwords = filter->length;
        char buf[256];
        for (i = 0; i < numwords; i++) {
            strcpy(buf, filter->list[i]);
            int j = 0;
            while (buf[j] != '\0')
            {
                char c = buf[j];
                char look = buf[j+1];

                // do FSA tables stuff
                token = fsadriver(filter);
                //printf("%c\n", c);
                j++;
            }
        }

        token->id = "id_tk"; 
    }
    return token;
}
