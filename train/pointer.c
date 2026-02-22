#include <stdio.h>

int main()
{
    char something[10][10];

    // Fill the 2-level array with values
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            something[i][j] = 'A' + (i + j) % 26; // Example: fill with alphabetic pattern
        }
    }

    for (int i = 0; i < 10; ++i){
        printf("row address: %p number: %d\n", something[i], i);

        for (int j = 0; j < 10; ++j){
            //printf(" row %d: %s collum: %d  item is %c\n",i, something[i],j,something[j][i]);
            printf("item %c  row[%d] collum[%d]\n", something[i][j],i,j);
            
         }
     }

     return 0;
}
