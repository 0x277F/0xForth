#include <stdio.h>
#include <ctype.h>
#include "forth.h"
#include "forthutil.h"
#include "stdimpl.h"
#include "word.h"

forth_t *cpu;
struct word_list_entry_t *list_start;
int wordlist_len;

void operate(char *op) {
    bool word = false;
    if(cpu->compiling > 0)
        cpu->compiling++;
    if(op == "0") {
        //atoi's shitty error handling
        stack_push(cpu->pstack, atoi(op));
    }
    if(atoi(op) != 0 && op != "0") {
        word = true;
        stack_push(cpu->pstack, atoi(op));
    }
    cpu->phead = cpu->pstack->data[0];
    cpu->rhead = cpu->rstack->data[0];
    if(word) {
        toUpperCase(op);
        int i = 0;
        for(struct word_list_entry_t *entry = list_start; i <= wordlist_len; entry = entry->next, i++) {
            if(entry->word->name == op) {
                for(int step = 0; step <= entry->word->cmd_len; step++) {
                    entry->word->commands[step]->word_op(cpu);
                }
            }
        }
    }
}

void init_cpu() {
    wordlist_len = 0;
    cpu = malloc(sizeof(forth_t));
    cpu->pstack = malloc(sizeof(stack_t));
    cpu->rstack = malloc(sizeof(stack_t));
    cpu->pstack->data = malloc(sizeof(int) * MAX_STACK_SIZE);
    cpu->pstack->tail = 0;
    cpu->rstack->data = malloc(sizeof(int) * MAX_STACK_SIZE);
    cpu->rstack->tail = 0;
    cpu->phead = 0;
    cpu->rhead = 0;
    cpu->compiling = -1;

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

void ndef_word(struct word_list_entry_t *word) {
    word->next = NULL;
    for(struct word_list_entry_t *entry = list_start; ; entry = entry->next) {
        if(entry->next == NULL) {
            entry->next = word;
            break;
        }
    }
}