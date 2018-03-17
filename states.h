#ifndef STATE_H_
#define STATE_H_

enum STATE {
    ERROR,
    INITIAL,
    ONE,
    TWO,
    OPERATOR,
    DELIM,
    IDENTIFIER,
    INTEGER,
    EQUALS,
    GREATER,
    LESS,
    COLON,
    PLUS,
    MINUS,
    STAR,
    FWDSLASH,
    PERCENT,
    PERIOD,
    LEFTPAREN,
    RIGHTPAREN,
    COMMA,
    LEFTCURLY,
    RIGHTCURLY,
    SEMICOLON,
    LEFTBRACKET,
    RIGHTBRACKET,
    AMPERSAND
};

#endif