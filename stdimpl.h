#ifndef INC_0XFORTH_STDIMPL_H
#define INC_0XFORTH_STDIMPL_H

#include <stdbool.h>
#include "stack.h"

typedef struct {
    stack_t *pstack; //Parameter stack
    int phead;
    stack_t *rstack; //Return stack
    int rhead;

    int compiling; //Inside a word definition. Index of wherever the definition began on the stack;
    bool string; //Inside the block opened with the PRINTSTRING word (.") and closed by a " (not a separate word).

    //Status callbacks
    void (*exitCallback)(); //Called on shutdown
    void (*operateCallback)(char *); //Called once per line of executable code

    //Output/Input Streams
    FILE *cpuin;
    FILE *cpuout;
    FILE *cpuerr;
} forth_t;

//Implementations of all standard words

inline void word_push(forth_t *cpu);
inline void word_startword(forth_t *cpu);
inline void word_endword(forth_t *cpu);
inline void word_print(forth_t *cpu);
inline void word_printstring(forth_t *cpu);
inline void word_plus(forth_t *cpu);
inline void word_sub(forth_t *cpu);
inline void word_mult(forth_t *cpu);
inline void word_div(forth_t *cpu);
inline void word_dup(forth_t *cpu);
inline void word_swap(forth_t *cpu);
inline void word_roll(forth_t *cpu);
inline void word_drop(forth_t *cpu);
inline void word_rot(forth_t *cpu);
inline void word_over(forth_t *cpu);
inline void word_tuck(forth_t *cpu);
inline void word_pick(forth_t *cpu);
inline void word_prntstack(forth_t *cpu);
inline void word_import(forth_t *cpu);
inline void word_bye(forth_t *cpu);

#endif //INC_0XFORTH_STDIMPL_H
