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
    vector<vector<int>> res;
    
    void dfs(TreeNode* root, vector<int>& path, int sum){
        if(!root) return;
        
        path.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == root->val)
                res.push_back(path);
            path.pop_back();
            return;
        }
        int remain = sum - root->val;
        dfs(root->left, path, remain);
        dfs(root->right, path, remain);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return vector<vector<int>>();
        vector<int> path;
        dfs(root, path, sum);
        return res;
    }
};