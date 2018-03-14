#include <stdlib.h>
#include <stdio.h>
#include "testscanner.h"
#include "metafile.h"

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

    // call test_scanner() function with interface and prep
    token_t* tk = testscanner(fp);
    printf("%s, %s, %d\n", tk->id, tk->instance, tk->line_num);

    // free fname if it was generated.
    if (!keyboardin) {
        free(fname);
    }
    fclose(fp);
    return 0;
}