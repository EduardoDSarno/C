#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

char* addBinary(char* a, char* b);

int main(void){
    char a[5] = "1011";
    char b[5] = "1110";

    //printf("%s\n %s\n", a,b);
    printf("%s",addBinary(a,b));
}


char* addBinary(char* a, char* b) {
    

    size_t lenA = strlen(a);
    size_t lenB = strlen(b);

    // Max(a,b)
    char *bigger  = (lenA >= lenB) ? a : b;
    char *smaller = (lenA >= lenB) ? b : a;

    char *result_str = malloc(strlen(bigger) + 2); // add null terminator and for the sizeof

    int i = strlen(bigger) - 1;
    int j = strlen(smaller) - 1;
    int c_in = 0;

    while (i >= 0) {
        int a = bigger[i] - '0';

        int b = (j >= 0) ? smaller[j] - '0' : 0;

        int total = a + b + c_in;

        int result = total % 2;
        c_in = total  / 2;

        result_str[i + 1] = (char)(result + '0');
        i--;
        j--;

    }

    result_str[strlen(bigger) + 1] = '\0'; // since bigger is where we allocate the memory MAX(a,b)

    if (c_in == 1){
        result_str[0] = '1';
    } else {
        memmove(result_str, result_str + 1, strlen(bigger) + 1);
    }
    return result_str;
}