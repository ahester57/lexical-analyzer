#include <stdlib.h>
#include <stdio.h>
#include "metafile.h"
#include "testscanner.h"
#include "filter.h"
#include "wordlist.h"
#include "token.h"

int
main(int argc, char** argv)
{
    // deal with command line arguments or lack thereof
    int keyboardin = 1;
    char* fname = "out";
    FILE* fp = stdin;
    // Parse arguments
    if (argc > 1) {
        keyboardin = 0;
        fname = getbasefilename(argv[1]);
        if (fname == NULL) {
            perror("Input error");
            return 1;
        }
        fp = openinputfile(fname);
    }
    if (fp == NULL) {
        perror("Input error");
        return 1;
    }

    // filter the file to get a wordlist_t
    wordlist_t* filter = filtersource(fp);
    fclose(fp);

    // Display filtered source
    displayfilter(filter);

    token_t** tokenlist = (token_t**) malloc(2048*sizeof(token_t*));
    // call test_scanner() function until EOF 
    printf("Watch the FSA work ... \n");
    printf("========================\n");
    int i = 0;
    while (1)
    {
        token_t* tk = testscanner(filter);
        if (tk == (token_t*)NULL)
            return 1;
        printf("%s, %s, %d\n", tk->id, tk->instance, tk->line_num);
        tokenlist[i] = tk;
        i++;
        if (isEOFtoken(tk))
            break;
    }
    int numtokens = i;
    printf("========================\n");

    printf("\nFinal token list, in order:\n");
    printf("========================\n");
    for (i = 0; i < numtokens; i++) {
        token_t* t = tokenlist[i];
        printf("%s, %s, %d\n", t->id, t->instance, t->line_num);
    }
    printf("========================\n");

    // free fname if it was generated.
    if (!keyboardin) {
        free(fname);
    }
    return 0;
}