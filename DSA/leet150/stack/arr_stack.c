#include "arr_stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack *new_stack(size_t max_size)
{
    Stack *stack = malloc(sizeof(Stack));

    if (stack == NULL)
    {
        return NULL;
    }

    stack->items = malloc(max_size * sizeof(void *));

    if (stack->items == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->count = 0;
    stack->max_size = max_size;

    return stack;
}

int push(Stack* stack, void * value)
{
    // if it is full
    if(stack->count == stack->max_size)
    {
        printf("stack is full\n");
        return 0;
    }
    else 
    {
        stack->items[stack->count] = value;
        stack->count++;
    }
    return 1;
}

/* re*/
int pop(Stack *stack)
{
    // if it is empty
    if(stack->count == 0)
    {
        printf("stack is empty, cant pop\n");
        return 0;
    }
    else 
    {
        stack->count--;
        stack->items[stack->count] = NULL; 
    }
    return 1;
}


static inline void *char_to_ptr(char c)
{
    return (void *)(intptr_t)c;
}
static inline char ptr_to_char(void *p)
{
    return (char)(intptr_t)p;
}