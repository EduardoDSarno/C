#include <stdio.h>
#include <string.h>
int strStr(char* haystack, char* needle);

int main(){

    char *hi = "aa";
    char *hello = "ab";
    printf("%d\n", strStr(hello, hi));
    //printf("%lu", sizeof(hi));
    return 0;
}

int strStr(char* haystack, char* needle) {

    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    
    // edge cases
    if (nlen >hlen) return -1;
    if (nlen == 0) return 0;

   for (int i = 0 ; i <= hlen - nlen; i++){

        for (int j = 0; j < nlen; j++){
            if (haystack[i + j] == needle[j]){
                // if the loop got in the last latter and was a match
                // it passes
                if (j == nlen - 1) return i;

                continue;
            }
            else {
                break;
            }
        }
        
   }
   return -1;
}