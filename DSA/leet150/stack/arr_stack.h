#ifndef ARR_STACK_H
#define ARR_STACK_H

#include <stddef.h>

typedef struct Stack
{
    void **items;
    size_t count;
    size_t max_size;
} Stack;

Stack *new_stack(size_t max_size);
int push(Stack *stack, void *value);
int pop(Stack *stack);

#endif
