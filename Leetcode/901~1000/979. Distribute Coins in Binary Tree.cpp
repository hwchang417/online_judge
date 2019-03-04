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
    int res;
    int dfs(TreeNode *root){
        if(root == NULL) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        res += abs(left) + abs(right);
        return left + right + root->val - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};