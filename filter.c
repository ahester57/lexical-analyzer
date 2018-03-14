#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "filter.h"
#include "wordlist.h"

static int commentflag = 0;

// create a 2-d array representation of the source file
// without spaces/ comments and include line numbers
// this does not split source into tokens yet
wordlist_t*
filtersource(FILE* fp)
{
    wordlist_t* list = (wordlist_t*) malloc(sizeof(wordlist_t));
    if (list == (wordlist_t*)NULL)
        return list;

    char* buf;
    size_t len = 0;
    ssize_t read;

    char** lines = (char**) malloc(256*sizeof(char*));
    if (lines == (char**)NULL)
        return (wordlist_t*)NULL;

    int i = 0;
    while ((read = getline(&buf, &len, fp)) != -1)
    {
        if (read > 0) {
            lines[i] = (char*) malloc(256*sizeof(char*));
            trimline(lines[i], buf);
            //strcpy(lines[i], buf);
            i++;
        }
    }
    list->list = lines;
    list->length = i;
    return list;
}

// trim spaces and comments out
void
trimline(char* dest, const char* src)
{
    int i = 0;
    int j = 0;
    char buf[256];
    char c = src[i];

    while (c != '\0')
    {
        if (c == '&') {
            // toggle comment
            commentflag = (commentflag + 1) % 2;
            if (commentflag == 0) {
                // marks end of comment
                i++;
                c = src[i];
                continue;
            }
        }
        if (commentflag) {
            // forget comments
            i++;
            c = src[i];
            continue;
        }
        if (c != ' ') {
            // if I may
            buf[j] = c;
            j++;
        }
        i++;
        c = src[i];
    }
    buf[j] = '\0';
    strcpy(dest, buf);
    return;
}
