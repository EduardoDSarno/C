#include <stddef.h>
#include <stdlib.h>
#include "arr_stack.h"
#include <stdint.h>
#include <string.h>

static inline void *char_to_ptr(char c)
{
    return (void *)(intptr_t)c;
}
static inline char ptr_to_char(void *p)
{
    return (char)(intptr_t)p;
}

int isValid(char* s) 
{
    size_t size = strlen(s);
    Stack *stack = new_stack(size);

    const char o_b1 = '{';
    const char o_b2 = '[';
    const char o_b3 = '(';

    const char c_b1 = '}';
    const char c_b2 = ']';
    const char c_b3 = ')';


    for(int i = 0; s[i] != '\0'; ++i)
    {
        if(s[i] == o_b1 || s[i] == o_b2 || s[i] == o_b3)
        {
            push(stack, char_to_ptr(s[i]));

        }
        else 
        {
            if (stack->count == 0) return 0;
            char top = ptr_to_char(stack->items[stack->count - 1]);

            if(s[i] == c_b1 && top == o_b1)
            {
                pop(stack);
            }
            else if (s[i] == c_b2 && top == o_b2) 
            {
                pop(stack);
            }
            else if (s[i] == c_b3 && top == o_b3) 
            {
                pop(stack);
            }
            else 
            {
                return 0;
            }
        }
    }
    int result = stack->count == 0;

        return result;
}