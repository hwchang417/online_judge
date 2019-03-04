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
    void traversal(TreeNode* root, int* diff, int* prev){
        int d;
        if(root == NULL) return;
        traversal(root->left, diff, prev);
        
        d = abs(*prev - root->val);
        if(*diff > d) *diff = d;
        *prev = root->val;
        
        traversal(root->right, diff, prev);
    }
    
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX, prev;
        if(!root) return 0;
        prev = INT_MAX >> 1;
        traversal(root, &diff, &prev);
        return diff;
    }
};