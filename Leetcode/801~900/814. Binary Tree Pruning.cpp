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
    bool cutOffNullNode(TreeNode* root){
        bool left, right;
        if(!root) return true;
        if(left = cutOffNullNode(root->left)) root->left = NULL;
        if(right = cutOffNullNode(root->right)) root->right = NULL;
        return root->val == 0 && left && right;
    }    
    
    TreeNode* pruneTree(TreeNode* root) {
        cutOffNullNode(root);
        return root;
    }
};