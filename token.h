#ifndef TOKEN_H_
#define TOKEN_H_

typedef struct {
    char* id;
    char* instance;
    int line_num;
} token_t;

#endif