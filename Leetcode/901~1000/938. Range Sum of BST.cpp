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
    void dfs(TreeNode* root, int L, int R, int* sum){
        if(root == NULL) return;
        dfs(root->left, L, R, sum);
        if(root->val > R) return;
        if(root->val >= L) *sum += root->val;
        dfs(root->right, L, R, sum);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        dfs(root, L, R, &sum);
        return sum;
    }
};