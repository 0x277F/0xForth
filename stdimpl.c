#include <stdio.h>
#include "stdimpl.h"

// Any number
inline void word_push(forth_t *cpu) {
    if(stack_push(cpu->pstack, cpu->phead) == 1) {
        fprintf(cpu->cpuerr, "Error pushing value to cpu: stack overflow");
    }
}

// :
inline void word_startword(forth_t *cpu) {
    cpu->compiling = 0;
}

// ;
inline void word_endword(forth_t *cpu) {
    cpu->compiling = -1;
}

// .
inline void word_print(forth_t *cpu) {
    fprintf(cpu->cpuout, "%d", stack_pop(cpu->pstack));
}

// ."
inline void word_printstring(forth_t *cpu) {
    cpu->string = true;
}

inline void word_plus(forth_t *cpu) {
    stack_push(cpu->pstack, stack_pop(cpu->pstack) + stack_pop(cpu->pstack));
}

inline void word_sub(forth_t *cpu) {
    int minus = stack_pop(cpu->pstack);
    stack_push(cpu->pstack, stack_pop(cpu->pstack) - minus);
}

inline void word_mult(forth_t *cpu) {
    stack_push(cpu->pstack, stack_pop(cpu->pstack) * stack_pop(cpu->pstack));
}

inline void word_div(forth_t *cpu) {
    int divisor = stack_pop(cpu->pstack);
    stack_push(cpu->pstack, stack_pop(cpu->pstack) / divisor);
}

inline void word_dup(forth_t *cpu) {
    stack_dup(cpu->pstack);
}

inline void word_swap(forth_t *cpu) {
    stack_swap(cpu->pstack);
}

inline void word_roll(forth_t *cpu) {
    stack_roll(cpu->pstack, stack_pop(cpu->pstack));
}

inline void word_drop(forth_t *cpu) {
    stack_drop(cpu->pstack);
}

inline void word_rot(forth_t *cpu) {
    stack_rot(cpu->pstack);
}

inline void word_over(forth_t *cpu) {
    stack_over(cpu->pstack);
}

inline void word_tuck(forth_t *cpu) {
    stack_tuck(cpu->pstack);
}

inline void word_pick(forth_t *cpu) {
    stack_pick(cpu->pstack, cpu->phead);
}

inline void word_prntstack(forth_t *cpu) {
    for (int i = 0; i <= cpu->pstack->tail; ++i) {
        printf("#%d: %d", i, cpu->pstack->data[i]);
    }
}

inline void word_import(forth_t *cpu) {

}

inline void word_bye(forth_t *cpu) {
    (*(cpu->exitCallback))();
}