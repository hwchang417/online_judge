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
    bool preorder(TreeNode* root, vector<int> &res, vector<int> &v, int &idx){
        if(root == NULL || idx >= v.size() - 1) return true;
        if(root->val == v[idx++]){
            if(root->left && root->left->val == v[idx]){
                return preorder(root->left, res, v, idx) && preorder(root->right, res, v, idx);
            }else if(root->right && root->right->val == v[idx]){
                if(!root->left) return preorder(root->right, res, v, idx);
                res.push_back(root->val);
                return preorder(root->right, res, v, idx) && preorder(root->left, res, v, idx);
            }
        }
        return !root->left && !root->right;
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int idx = 0;
        vector<int> res, fail;
        if(root == NULL) return res;
        if(!preorder(root, res, voyage, idx)){ 
            fail.push_back(-1); 
            return fail;
        }
        return res;
    }
};