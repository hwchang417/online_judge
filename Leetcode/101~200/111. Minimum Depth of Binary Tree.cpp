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
    void minDepth(TreeNode* root, int depth, int& min){
        if(root->left == NULL && root->right == NULL) if(depth < min) min = depth;
        if(root->left)
            minDepth(root->left, depth + 1, min);
        if(root->right)
            minDepth(root->right, depth + 1, min);
    }
    
    int minDepth(TreeNode* root) {
        int min = INT_MAX;
        if(root == NULL) return 0;
        minDepth(root, 1, min);
        return min;
    }
};