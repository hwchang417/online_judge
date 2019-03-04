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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *prev = NULL, *tmp = root;
        
        while(tmp){
            prev = tmp;
            tmp = tmp->val < val ? tmp->right : tmp->left;
        }
        
        if(prev->val < val) prev->right = new TreeNode(val);
        else prev->left = new TreeNode(val);
        
        return root;
    }
};