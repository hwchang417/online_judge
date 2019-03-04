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
    int findSecondMinimumValue(TreeNode* root) {
        int right, left;
        if(root->left == NULL) return -1;
        
        left = root->val == root->left->val ? findSecondMinimumValue(root->left) : root->left->val;
        right = root->val == root->right->val ? findSecondMinimumValue(root->right) : root->right->val;

        return left == -1 || right == -1 ? max(left, right) : min(left, right);
    }
};