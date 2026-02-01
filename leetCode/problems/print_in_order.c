#include <stdlib.h>
#include <semaphore.h>

// 1114. Print in Order
// Easy
// Topics
// premium lock icon
// Companies
// Suppose we have a class:

// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }
// The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

// Note:

// We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: "firstsecondthird"
// Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
// Example 2:

// Input: nums = [1,3,2]
// Output: "firstsecondthird"
// Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 

// Constraints:

// nums is a permutation of [1, 2, 3].
// int main(){
//     return 0;
// }

typedef struct 
{
    // User defined data may be declared here.
    // Use pthreads semaphores for thread synchronization
    sem_t sem1;
    sem_t sem2;
    
} Foo;

// Function Declaration, do not remove
void printFirst();
void printSecond();
void printThird();

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    sem_init(&obj->sem1 ,0,0);
    sem_init(&obj->sem2 ,0,0);
    
    return obj;
}

void first(Foo* obj) 
{
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&obj->sem1);
}

void second(Foo* obj) 
{
    sem_wait(&obj->sem1);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&obj->sem2);
}

void third(Foo* obj) {
    sem_wait(&obj->sem2);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj);
}