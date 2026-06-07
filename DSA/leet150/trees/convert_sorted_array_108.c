#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>


typedef struct TreeNode
{
   int val;
   struct TreeNode * right;
   struct TreeNode * left;
} TreeNode;
TreeNode * helper(int * nums, int left,int right);

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) 
{
    
    int left = 0;
    int right = numsSize - 1;

    return helper(nums, left, right);

}

struct TreeNode * helper(int * nums, int left,int right)
{
    // base   
    if(left > right)
    {
        return NULL;
    }
    int mid = (left + right) / 2;

    struct TreeNode * root = malloc(sizeof(struct TreeNode));
    if(root == NULL) return NULL;

    root->val = nums[mid];

    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    
    return root;

}
