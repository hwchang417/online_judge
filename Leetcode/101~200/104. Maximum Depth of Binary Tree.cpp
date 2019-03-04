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
    int depth(TreeNode* root, int dep){
        int ldep, rdep;
        if(root == NULL) return dep - 1;
        
        ldep = depth(root->left, dep + 1);
        rdep = depth(root->right, dep + 1);
        
        return ldep > rdep ? ldep : rdep;
    }
    
    int maxDepth(TreeNode* root) {
        return depth(root, 1);
    }
};