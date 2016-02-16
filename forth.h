#ifndef INC_0XFORTH_FORTH_H
#define INC_0XFORTH_FORTH_H

#include "stack.h"
#include "word.h"
#include "stdimpl.h"
#include "khash.h"
#include <stdbool.h>

extern forth_t *cpu;

void operate(char *statement);

void init_cpu();

void stop_cpu();

#endif //INC_0XFORTH_FORTH_H
