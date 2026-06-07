#include <stdio.h>

int main()
{

}

typedef struct TreeNode
{
   int val;
   struct TreeNode * right;
   struct TreeNode * left;
} TreeNode;

int isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    // base case
    if (p == NULL && q == NULL) return 1; 
    if (p == NULL || q == NULL) return 0;

    if(p->val != q->val) return 0;

    return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);

}