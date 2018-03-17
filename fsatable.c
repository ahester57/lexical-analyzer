#include <stdlib.h>
#include <string.h>
#include "fsatable.h"
#include "alphabet.h"

int
fsatable(const int state, const char nextchar)
{
    int nextstate = NULL;
    
    switch (state)
    {
        case 0:
            if (isoperator(nextchar)) {
                return 'o';
            }
            if (isdelim(nextchar)) {
                return 'd';
            }
            if (isletter(nextchar)) {
                return 1;
            }
            if (isnumber(nextchar)) {
                return 2;
            }
            break;
        case 1:
            if (isoperator(nextchar)) {
                return 'i';
            }
            if (isdelim(nextchar)) {
                return 'i';
            }
            if (isletter(nextchar)) {
                return 1;
            }
            if (isnumber(nextchar)) {
                return 1;
            }
            break;
        case 2:
            if (isoperator(nextchar)) {
                return 'n';
            }
            if (isdelim(nextchar)) {
                return 'n';
            }
            if (isletter(nextchar)) {
                return 'n';
            }
            if (isnumber(nextchar)) {
                return 2;
            }
            break;
    }
    return nextstate;
}

int
operatortable(const int state, const char nextchar)
{

    int nextstate = NULL;

    return nextstate;
}

int
delimtable(const int state, const char nextchar)
{

    int nextstate = NULL;

    return nextstate;
}