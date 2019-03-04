/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode* root, int* sum){
        
        if(root->right) traversal(root->right, sum);
        *sum += root->val;
        root->val = *sum;
        if(root->left) traversal(root->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        if(root) traversal(root, &sum);
        return root;
    }
};