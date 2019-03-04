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
    void maxValueInTree(TreeNode* root, vector<int>& res, int depth){
        if(root == NULL) return;
        
        if(res.size() == depth)
            res.push_back(root->val);
        else if(root->val > res[depth])
            res[depth] = root->val;
        
        maxValueInTree(root->left, res, depth + 1);
        maxValueInTree(root->right, res, depth + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        maxValueInTree(root, res, 0);
        return res;
    }
};