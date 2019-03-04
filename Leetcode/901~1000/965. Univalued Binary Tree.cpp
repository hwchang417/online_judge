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
    bool isUnivalTree(TreeNode* root) {
        bool res = true;
        if(root == NULL) return true;
        res &= !(root->left && root->val != root->left->val) & !(root->right && root->val != root->right->val);
        return res && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};