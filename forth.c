#include <stdio.h>
#include "forth.h"
#include "forthutil.h"

KHASH_MAP_INIT_STR(32, void*)

forth_t *cpu;

khiter_t iter;

void operate(char *statement) {
    cpu->phead = cpu->pstack->data[0];
    cpu->rhead = cpu->rstack->data[0];
    int words = countWords(statement) + 1;
    char **ops = malloc(sizeof(char*) * words);
    for(int i = 0; i<=words; i++) {
        ops[i] = malloc(sizeof(char) * 16);
    }
    int word = 0;
    int counter = 0;
    ops[word][0] = statement[0];
    while(statement++) {
        if(statement[0] != ' ') {
            ops[word][counter] = statement[0];
            counter++;
        } else {
            word++;
            counter = 0;
        }
    }
    for(int i = 0; i<words; i++) {
        char *op = ops[i];

    }
}

void init_cpu() {
    khash_t(32) *h = kh_init(32);

    cpu = malloc(sizeof(forth_t));
    cpu->pstack = malloc(sizeof(stack_t));
    cpu->rstack = malloc(sizeof(stack_t));
    cpu->pstack->data = malloc(sizeof(int) * MAX_STACK_SIZE);
    cpu->pstack->tail = 0;
    cpu->rstack->data = malloc(sizeof(int) * MAX_STACK_SIZE);
    cpu->rstack->tail = 0;
    cpu->phead = 0;
    cpu->rhead = 0;

    cpu->exitCallback = &stop_cpu;
    cpu->operateCallback = &operate;
}

void stop_cpu() {
    printf("CPU is stopping!");
    free(cpu->pstack->data);
    free(cpu->rstack->data);
    free(cpu->pstack);
    free(cpu->rstack);
    free(cpu);
    printf("Shutdown complete.");
}
