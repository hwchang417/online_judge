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
    
    void traversal(vector<vector<int>>& res, TreeNode* root, int dep){
        if(!root) return;
        
        if(res.size() <= dep)
            res.push_back(vector<int>());
        res[dep].push_back(root->val);
        
        traversal(res, root->left, dep + 1);
        traversal(res, root->right, dep + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int index, size;
        vector<vector<int>> tmp, res;
        traversal(tmp, root, 0);
        size = tmp.size() - 1;
        for(index = 0;index <= size;index++){
            res.push_back(tmp[size - index]);
        }
        return res;
    }
};