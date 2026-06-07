#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
   int val;
   struct TreeNode * right;
   struct TreeNode * left;
} TreeNode;

int hasPathSum(struct TreeNode* root, int targetSum) 
{
    if (root == NULL) return 0;
    if(root->left == NULL && root->right == NULL)
    {
        return root->val == targetSum;
    }
  

    return hasPathSum(root->left, targetSum - root->val) ||
       hasPathSum(root->right, targetSum - root->val);

}