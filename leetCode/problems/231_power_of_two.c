
#include <stdio.h>
int isPowerOfTwo(int n);


int main(){
    isPowerOfTwo(24);
    return 0;
}

// an effective way to do this is using binary because
// power of 2 numbers start w/ 1 and have just zeros following
// making a O(N)
int isPowerOfTwo(int n) 
{
    if (n <= 0) return 0;
    // n is a power of two if it has only one bit set
    return (n & (n - 1)) == 0;
}



