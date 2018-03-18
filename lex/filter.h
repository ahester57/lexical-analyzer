#ifndef FILTER_H_
#define FILTER_H_
#include "wordlist.h"
#include <stdio.h>

wordlist_t* filtersource(FILE* fp);
void trimline(char* dest, const char* src);

#endif