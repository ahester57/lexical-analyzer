#include <stdlib.h>
#include <stdio.h>
#include "metafile.h"
#include "testscanner.h"
#include "filter.h"
#include "wordlist.h"

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
    int i;
    fprintf(stderr, "NUM_LINES = %d\n", filter->length);
    for (i = 0; i < filter->length; i++) {
        //fprintf(stderr,"%s", filter->list[i]);
    }

    // call test_scanner() function with interface and prep
    token_t* tk = testscanner(filter);
    printf("%s, %s, %d\n", tk->id, tk->instance, tk->line_num);

    //printf("%d\n", iskeyword("stop"));
    // free fname if it was generated.
    if (!keyboardin) {
        free(fname);
    }
    return 0;
}