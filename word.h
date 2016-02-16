#ifndef INC_0XFORTH_WORD_H
#define INC_0XFORTH_WORD_H

#include <stddef.h>

typedef enum {
    PUSH,
    STARTWORD,
    ENDWORD,
    PRINT,
    PRINTSTRING,
    PLUS,
    SUB,
    MULT,
    DIV,
    DUP,
    SWAP,
    ROLL,
    DROP,
    ROT,
    OVER,
    TUCK,
    PICK,
    PRNTSTACK,
    IMPORT,
    BYE,
} forth_op_t;

typedef struct {
    char *name;
    forth_op_t *commands;
    size_t length;
} word_t;

#endif //INC_0XFORTH_WORD_H
