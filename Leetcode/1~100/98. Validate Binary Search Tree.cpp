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
    
    bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX) {
        if(root == NULL) return true;
        if(root->val <= min || root->val >= max) return false;
        if(root->left != NULL && root->val <= root->left->val) return false;
        if(root->right != NULL && root->val >= root->right->val) return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    /*
    bool isValidSubTree(TreeNode* root, int greater, int less){
        if(root == NULL) return true;
        
        if(root->val < greater || root->val > less) return false;
        if(root->left != NULL && root->val <= root->left->val) return false;
        if(root->right != NULL && root->val >= root->right->val) return false;
        
        if(!isValidSubTree(root->left, greater, root->val - 1)) return false;
        if(!isValidSubTree(root->right, root->val + 1, less)) return false;
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL) return true;
        return isValidSubTree(root, -2147483648, 2147483647);
    }
    */
    
};