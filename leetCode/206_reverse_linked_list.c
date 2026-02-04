#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* reverseList(struct ListNode* head) 
{
   struct ListNode *prev = NULL;
   struct ListNode *next = NULL;
   struct ListNode *currentHead = head;

    while (currentHead != NULL){
        

        next = currentHead->next; // save next

        currentHead->next = prev; // flip arrow meaning "hey current your next is now prev <-"
        prev = currentHead; // advacing prev foward after
        currentHead = next; // and than more current foward, so that next goes more foward, the currentHead.next will point to the new advanced prev
                            // and we will move both foward again finishing the loop
       
    
    }
    return prev;
}









