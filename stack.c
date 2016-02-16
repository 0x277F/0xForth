#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//http://galileo.phys.virginia.edu/classes/551.jvn.fall01/primer.htm#param

inline int stack_push(stack_t *stack, int value) {
    /**
    realloc(stack->data, stack->tail+1);
    int *data = stack->data;
    for (int i = stack->tail+1; i>0; --i) {
        data[i] = data[i-1];
    }
    data[0] = value;
    stack->tail++; **/
    if(stack->tail == MAX_STACK_SIZE) {
        fprintf(stderr, "Stack Overflow Error");
        return 1;
    } else {
        memmove(stack->data+1, stack->data, stack->tail);
        stack->tail++;
        stack->data[0] = value;
        return 0;
    }
}

int stack_pop_(stack_t *stack) {
    int *data = stack->data;
    int head = data[0];
    for (int i = 0; i<stack->tail; i++) {
        data[i] = data[i++];
    }
    data[stack->tail] = 0;
    realloc(stack->data, stack->tail-1);
    stack->tail--;
    return head;
}

//Use this instead of stack_pop_ whenever possible
inline int stack_pop(stack_t *stack) {
    int i = stack->data[0];
    stack_drop(stack);
    return i;
}

inline void stack_drop(stack_t *stack) {
    memmove(stack->data, stack->data+1, stack->tail);
    stack->tail--;
}

inline void stack_swap_(stack_t *stack, int loc1, int loc2) {
    int l1_value = stack->data[loc1];
    stack->data[loc1] = stack->data[loc2];
    stack->data[loc2] = l1_value;
}

inline void stack_swap(stack_t *stack) {
    stack_swap_(stack, 0, 1);
}

inline void stack_dup(stack_t *stack) {
    stack_push(stack, stack->data[0]);
}

inline void stack_rot(stack_t *stack) {
    int l0 = stack->data[0];
    int l1 = stack->data[1];
    int l2 = stack->data[2];
    stack->data[0] = l2;
    stack->data[1] = l0;
    stack->data[2] = l1;
}

inline void stack_over(stack_t *stack) {
    stack_push(stack, stack->data[1]);
}

inline void stack_tuck(stack_t *stack) {
    int head = stack->data[0];
    stack_swap(stack);
    stack_push(stack, head);
}

inline void stack_pick(stack_t *stack, int index) {
    stack_push(stack, stack->data[index]);
}

inline void stack_roll(stack_t *stack, int index) {
    int val = stack->data[index];
    memmove(stack->data+index, stack->data+index+1, stack->tail - index);
    stack_push(stack, val);
}

