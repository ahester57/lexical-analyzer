#ifndef SCANNER_H_
#define SCANNER_H_
#include "wordlist.h"
#include "token.h"

token_t* scanner(wordlist_t* filter);

#endif