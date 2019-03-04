/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void swapSubtree(struct TreeNode* root) {
    
    if(root == NULL) return;
        
    struct TreeNode* tmp;
    
    tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    
    swapSubtree(root->right);
    swapSubtree(root->left);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    swapSubtree(root);
    return root;
}