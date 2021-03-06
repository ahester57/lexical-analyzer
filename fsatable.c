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
        // case: error
        case ERROR:
            nextstate = ERROR;
            break;
        // case: initial state
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
            if (nextchar == '\t')
                nextstate = EOFILE;
            break;
        // case: the beginnings of an identifier
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
            if (nextchar == '\t')
                nextstate = IDENTIFIER;
            break;
        // case: the beginnings of an integer
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
            if (nextchar == '\t')
                nextstate = INTEGER;
            break;
        default:
            nextstate = ERROR;
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
    switch (state)
    {
        case INITIAL:
            if (nextchar == '=') {
                nextstate = EQUALS;
                break;
            }
            if (nextchar == '>') {
                nextstate = GREATER;
                break;
            }
            if (nextchar == '<') {
                nextstate = LESS;
                break;
            }
            if (nextchar == ':') {
                nextstate = COLON;
                break;
            }
            if (nextchar == '+') {
                nextstate = PLUS;
                break;
            }
            if (nextchar == '-') {
                nextstate = MINUS;
                break;
            }
            if (nextchar == '*') {
                nextstate = STAR;
                break;
            }
            if (nextchar == '/') {
                nextstate = FWDSLASH;
                break;
            }
            if (nextchar == '%') {
                nextstate = PERCENT;
                break;
            }
            break;
        default:
            nextstate = ERROR;
    }
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
        // init. delims end any other token
        case INITIAL:
            if (nextchar == '.') {
                nextstate = PERIOD;
                break;
            }
            if (nextchar == '(') {
                nextstate = LEFTPAREN;
                break;
            }
            if (nextchar == ')') {
                nextstate = RIGHTPAREN;
                break;
            }
            if (nextchar == ',') {
                nextstate = COMMA;
                break;
            }
            if (nextchar == '{') {
                nextstate = LEFTCURLY;
                break;
            }
            if (nextchar == '}') {
                nextstate = RIGHTCURLY;
                break;
            }
            if (nextchar == ';') {
                nextstate = SEMICOLON;
                break;
            }
            if (nextchar == '[') {
                nextstate = LEFTBRACKET;
                break;
            }
            if (nextchar == ']') {
                nextstate = RIGHTBRACKET;
                break;
            }
            if (nextchar == '&') {
                nextstate = AMPERSAND;
                break;
            }
            break;
        default:
            nextstate = ERROR;
    }
    return nextstate;
}