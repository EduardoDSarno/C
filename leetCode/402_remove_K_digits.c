// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

// Constraints:

// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

#include <string.h>
char* removeKdigits(char* num, int k);

int main(){
    char num[] = "1432219";
    removeKdigits(num, 3);
}

#include <stdio.h>
char* removeKdigits(char* num, int k) {
    // return 0 if the char that have to be taken are bigger then num lenght.
    if (strlen(num) <= k){
        //printf("your result is 0");
        return "0";
    }

     int i = 0;
    // for char in num
    while (k > 0 && num[i+1] != '\0')
    {
        // if char <= char.next -> pop char.next k--1
        if (num[i] > num[i + 1]){
            memmove(&num[i], &num[i+1], strlen(num) - (i));
            k--;
            if (i>0){
                i--;
            }
        }
        // else -> pop char k --1
        else {
            i++;
        }
        
    }

    //handke case where k >0 when there is no more numers
    while (k > 0) {
        int len = strlen(num);
        if (len > 0) {
            num[len - 1] = '\0'; // delete last digit
        }
        k--;
    }
    //if char has zero to the left, pop them
    i = 0;
    while (num[i] == '0'){
        i++;
    }
    if (num[i] == '\0'){
        return "0";
    }
    return num + i;
}