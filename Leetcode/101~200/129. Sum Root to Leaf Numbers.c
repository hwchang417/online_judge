/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void sumFromRootToLeaf(struct TreeNode* root, int* sum, int number){
    
    if(root == NULL)
        return;
    
    number = (number << 3) + (number << 1) + root->val;
    
    if(root->left == NULL && root->right == NULL){
        *sum += number;
        return;
    }
    
    sumFromRootToLeaf(root->left, sum, number);
    sumFromRootToLeaf(root->right, sum, number);
}

int sumNumbers(struct TreeNode* root) {
    int sum = 0;
    sumFromRootToLeaf(root, &sum, 0);
    return sum;
}