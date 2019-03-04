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
    TreeNode* res = new TreeNode(0), *node = res;
    
    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            res->right = new TreeNode(root->val);
            res = res->right;
            dfs(root->right);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* tmp = node->right;
        delete node;
        return tmp;
    }
};