#ifndef INC_0XFORTH_FORTH_H
#define INC_0XFORTH_FORTH_H

#include "stack.h"
#include "word.h"
#include "stdimpl.h"
#include <stdbool.h>

extern forth_t *cpu;
extern struct word_list_entry_t *list_start;
extern int wordlist_len;

struct word_list_entry_t {
    word_t *word;
    struct word_list_entry_t *next;
};

void operate(char *statement);

void init_cpu();

void stop_cpu();

void ndef_word(struct word_list_entry_t *word);

#endif //INC_0XFORTH_FORTH_H
