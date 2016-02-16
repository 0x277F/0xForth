#ifndef INC_0XFORTH_STACK_H
#define INC_0XFORTH_STACK_H

#define MAX_STACK_SIZE 64

#include <stdlib.h>

typedef struct {
    int *data;
    size_t tail;
} stack_t;

inline int stack_push(stack_t *stack, int value);

int stack_pop_(stack_t *stack);

inline int stack_pop(stack_t *stack);

inline void stack_drop(stack_t *stack);

inline void stack_swap_(stack_t *stack, int loc1, int loc2);

inline void stack_swap(stack_t *stack);

inline void stack_dup(stack_t *stack);

inline void stack_rot(stack_t *stack);

inline void stack_over(stack_t *stack);

inline void stack_tuck(stack_t *stack);

inline void stack_pick(stack_t *stack, int index);

inline void stack_roll(stack_t *stack, int index);

#endif //INC_0XFORTH_STACK_H
