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
    fprintf(stderr, "%c\n", 'c');
    token_t* token = (token_t*) malloc(sizeof(token_t));
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
                printf("%c\n", c);

                // do FSA tables stuff
                //token = fsadriver(filter);
                j++;
            }
        }

        token->id = "id_tk"; 
    }
    return token;
}
