#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node * next;
    int min;
} Node;

typedef struct MinStack
{
    Node *head;
    size_t size;
} MinStack;


MinStack* minStackCreate() 
{
    MinStack *stack = malloc(sizeof(MinStack));
    if(stack == NULL) return NULL;
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void minStackPush(MinStack* obj, int val) 
{
    Node *node = malloc(sizeof(Node));
    if(node == NULL)return;
    
    node->next = NULL;
    node->value = val;

    if(obj->size == 0)
    {
        node->min = val;
    }
    else 
    {
        if(obj->head->min > val)
        {
            node->min = val;
        }
        else 
        {
            node->min = obj->head->min;
        }
        // making the linke between the current node to the head
        node->next = obj->head;
    }
    // replacing head
    obj->head = node;
    obj->size++;
    
}

void minStackPop(MinStack* obj) 
{
    if (obj->size == 0) return;
    Node * temp = obj->head;
    // removing the link
    obj->head = obj->head->next;
    free(temp);
    obj->size--;
}

int minStackTop(MinStack* obj) 
{
    return obj->head->value;
}

int minStackGetMin(MinStack* obj) 
{
    return obj->head->min;
}

void minStackFree(MinStack* obj) 
{
    if (obj == NULL) return;
    while (obj->head != NULL) 
    {
        Node * temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/