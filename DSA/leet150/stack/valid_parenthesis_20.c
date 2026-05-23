#include <stddef.h>
#include <stdlib.h>
#include "arr_stack.h"
int isValid(char* s) 
{
    size_t size = sizeof(s);
    Stack *stack = new_stack(size);

    const char o_b1 = '{';
    const char o_b2 = '[';
    const char o_b3 = '(';

    const char c_b1 = '}';
    const char c_b2 = ']';
    const char c_b3 = ')';


    for(int i = 0; i < size - 1; ++i)
    {
        int count = 0;
        if(s[i] == o_b1 || s[i] == o_b2 || s[i] == o_b3)
        {
            stack[count] = s[i];
            count++;
        }
        else 
        {
            if(s[i] == c_b1 && stack[count] == o_b1)
            {
                
            }
        }

    }
}