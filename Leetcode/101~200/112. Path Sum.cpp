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
    
    //dfs走訪，用走法來命名
    //可以用相減的方式，少傳一個參數
    //
    bool dfs(TreeNode* root, int sum){
        if(!root) return false;
        int tmp = sum - root->val;
        if(!root->left && !root->right)    return !tmp;
        return dfs(root->left, tmp) || dfs(root->right, tmp);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        return dfs(root, sum);
    }
};