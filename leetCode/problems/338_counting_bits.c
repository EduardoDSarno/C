/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Given an integer n, return an array ans of length n + 1 
//such that for each i (0 <= i <= n), ans[i] is the number of 1's in 
// the binary representation of i.

 

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

#include <stdio.h>
#include <stdlib.h>

int* countBits (int n , int* returnSize);
void print_binary(int n);

int main(){
    print_binary(10);
    return 0;
}

int* countBits(int n, int* returnSize) {
    
    int *array = malloc((n + 1) * sizeof(int)); // array of lenght n + 1
    *returnSize = n + 1; // set return size
    for (int i = 0; i <= n; i++){
        // so for each i in N we want to get i in bits
        int ones_count = 0;
        for (int j = 0; j < 32; j++) // bits just go to 32 max not to value of i
        {
            // than we want to check how many 1 there're on i_bits 
            if((i >> j) & 1){
                ones_count++;
            }
        }
        // add this number to array[i]
        array[i] = ones_count;
        
    }
    return array;
}


