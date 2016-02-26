#ifndef INC_0XFORTH_WORD_H
#define INC_0XFORTH_WORD_H

#include <stddef.h>
#include "stdimpl.h"

typedef struct {
    char *name;
    void (*word_op)(forth_t *);
} forth_op_t;

typedef struct {
    char *name;
    forth_op_t **commands;
    size_t cmd_len;
} word_t;

#endif //INC_0XFORTH_WORD_H
