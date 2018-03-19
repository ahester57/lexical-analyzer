#ifndef TOKEN_H_
#define TOKEN_H_
#include "states.h"

typedef struct {
    const char* id;
    char* instance;
    int line_num;
} token_t;

const char* gettoken(const enum STATE state);
int isEOFtoken(const token_t* token);
void maketoken(token_t* token,
              const enum STATE state,
              char* string,
              const int line);
void copytoken(token_t* dest, const token_t* src);

#endif