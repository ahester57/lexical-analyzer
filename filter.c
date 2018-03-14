#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "filter.h"

char**
filtersource(FILE* fp)
{
    char* buf;
    size_t len = 0;
    ssize_t read;

    char** lines = (char**) malloc(256*sizeof(char*));
    if (lines == (char**)NULL)
        return lines;

    int i = 0;
    while ((read = getline(&buf, &len, fp)) != -1)
    {
        if (read > 0) {
            lines[i] = (char*) malloc(128*sizeof(char*));
            strcpy(lines[i], buf);
            i++;
        }
    }
    return lines;
}