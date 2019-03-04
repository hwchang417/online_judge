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
    int min_num, max_depth, value;
    
    void traversal(TreeNode* root, int depth, int num){
        if(root == NULL) return;
        if(depth > max_depth || (depth == max_depth && num < min_num))
            max_depth = depth, min_num = num, value = root->val;
        traversal(root->left, depth + 1, num - 1);
        traversal(root->right, depth + 1, num + 1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        max_depth = INT_MIN; value = -1;
        traversal(root, 0, 0);
        return value;
    }
};