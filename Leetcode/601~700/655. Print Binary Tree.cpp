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
    
    int findDepth(TreeNode* root){
        if(root == NULL) return 0;
        return max(findDepth(root->left), findDepth(root->right)) + 1;
    }
    
    void put(vector<vector<string>>& res, TreeNode* root, int dep, int max_dep, int left, int right){
        if(root == NULL) return;
        
        int mid = (left + right) >> 1;
        res[dep - 1][mid] = to_string(root->val);
        
        put(res, root->left, dep + 1, max_dep, left, mid - 1);
        put(res, root->right, dep + 1, max_dep, mid + 1, right);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int m = INT_MIN;
        vector<vector<string>> res;
        
        m = findDepth(root);
        res.resize(m, vector<string>((1 << m) - 1, ""));
        put(res, root, 1, m, 0, (1 << m) - 2);
        
        return res;
    }
};