#include <stdlib.h>
#include <string.h>
#include "fsatable.h"
#include "alphabet.h"
#include "states.h"

enum STATE
fsatable(const enum STATE state, const char nextchar)
{
    enum STATE nextstate = ERROR;
    // sorry for this 
    // i should have a function that nextstate =s an int 
    // that i switch upon, but in reality that is the
    // same amount of calculations
    switch (state)
    {
        // case 0: initial state
        case INITIAL:
            if (isoperator(nextchar)) {
                nextstate = OPERATOR;
            }
            if (isdelim(nextchar)) {
                nextstate = DELIM;
            }
            if (isletter(nextchar)) {
                nextstate = ONE;
            }
            if (isnumber(nextchar)) {
                nextstate = TWO;
            }
            break;
        // case 1: the beginnings of an identifier
        case ONE:
            if (isoperator(nextchar)) {
                nextstate = IDENTIFIER;
            }
            if (isdelim(nextchar)) {
                nextstate = IDENTIFIER;
            }
            if (isletter(nextchar)) {
                nextstate = ONE;
            }
            if (isnumber(nextchar)) {
                nextstate = ONE;
            }
            break;
        // case 2: the beginnings of an integer
        case TWO:
            if (isoperator(nextchar)) {
                nextstate = INTEGER;
            }
            if (isdelim(nextchar)) {
                nextstate = INTEGER;
            }
            if (isletter(nextchar)) {
                nextstate = INTEGER;
            }
            if (isnumber(nextchar)) {
                nextstate = TWO;
            }
            break;
    }
    if (nextstate == OPERATOR) {
        nextstate = operatortable(state, nextchar);
    }
    if (nextstate == DELIM) {
        nextstate = delimtable(state, nextchar);
    }
    return nextstate;
}

// operator token stuff
enum STATE
operatortable(const int state, const char nextchar)
{

    enum STATE nextstate = ERROR;

    return nextstate;
}

// delimiter token stuff,
// divide and conquer even if it's not for efficiency
enum STATE
delimtable(const int state, const char nextchar)
{

    enum STATE nextstate = ERROR;
    switch (state) 
    {
        // only 1 case here, init. delims end any other token
        case 0:
            if (nextchar == '.') {

            }
            if (nextchar == '.') {

            }
            if (nextchar == '.') {

            }
            if (nextchar == '.') {

            }
            if (nextchar == '.') {

            }
            if (nextchar == '.') {

            }
            if (nextchar == '.') {

            }
            break;
    }
    return nextstate;
}