#ifndef TOKEN_H_
#define TOKEN_H_
#include "states.h"

typedef struct {
    const char* id;
    char* instance;
    int line_num;
} token_t;

const char* gettoken(const enum STATE state);

#endif