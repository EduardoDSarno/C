
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int isUgly(int n);
int isPrime(int m);
// An ugly number is a positive integer which does not 
// have a prime factor other than 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.

 

// Example 1:

// Input: n = 6
// Output: true
// Explanation: 6 = 2 × 3
// Example 2:

// Input: n = 1
// Output: true
// Explanation: 1 has no prime factors.
// Example 3:

// Input: n = 14
// Output: false
// Explanation: 14 is not ugly since it includes the prime factor 7.


int main(){
    printf("%d\n", isPrime(12));
    return 0;
    
}

int isPrime(int m){

    // loop throught 2 and m-1 because prime numbers defition if to have athat is 1 and the own number
    // 
    for(int i = 2; i < m; ++i){
        int result = m % i;

        if (result == 0){
            return 0;
        }
    }
    return 1;
}

int isUgly(int n) {

    if (n == 0) return 0;

    int allowed_primes[3] = {2,3,5};

    for (int i = 0; i <= 3; ++i){
        while (n % allowed_primes[i] == 0) {
            n /= allowed_primes[i];
        }
    }
   return n == 1;

}