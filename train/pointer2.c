#include <stdio.h>

int main()
{
    char something[5][5] = {0};

    for (int i = 0; i < 5; ++i) 
    {
        printf("row = %d\n", i);
        for (int j = 0; j < 5; j++)
        {
            printf("value = %c\n", something[i][j]);
        }
        puts("");
    }

    return 0;
}