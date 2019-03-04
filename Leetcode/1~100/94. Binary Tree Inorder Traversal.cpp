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
    
    void traversal(TreeNode* root, vector<int>& res){
        
        if(!root) return;
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        res = vector<int>();
        traversal(root, res);
        return res;
    }
};