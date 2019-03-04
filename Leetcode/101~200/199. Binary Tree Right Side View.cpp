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
    
    void rightTraversal(vector<int> &res, TreeNode* root, int depth){
        //檢查左右子樹的深度，並走訪節點，到某個深度之後
        if(root == NULL)
            return;
        
        //只有深度等於size時，才要放，其餘不放只走訪
        if(depth == res.size())
            res.push_back(root->val);
        rightTraversal(res, root->right, depth + 1);
        rightTraversal(res, root->left, depth + 1);
    }
        
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightTraversal(res, root, 0);
        return res;
    }
};