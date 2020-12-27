#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef void* LINKEDLIST;

LINKEDLIST ll_init(void);

void stack_push(LINKEDLIST linkedlist, char input);

void stack_pop(LINKEDLIST linkedlist);

int stack_check(LINKEDLIST linkedlist, char input);

void stack_print(LINKEDLIST linkedlist);

int stack_empty_check(LINKEDLIST hStack);

void stack_clear(LINKEDLIST* hStack);

void clear_kb();

#endif