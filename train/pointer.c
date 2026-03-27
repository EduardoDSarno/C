#include <stdio.h>

int main()
{
    int x = 42;
    int *p = &x;

    printf("%p\n", p);   // undefined behavior — might print something like 1606415148
    printf("%p\n", (void *)p);  // correct — prints something like 0x7ffd5fc2a3bc
    int const hi = 33;

    
    int fn(int array[], int *array2);
}
