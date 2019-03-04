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
	
    bool isSameNode(TreeNode* p, TreeNode* q) {
        bool res;
        res = true;
        if(p == NULL || q == NULL) return (p == q);
        return p->val == q->val 
			   && isSameNode(p->left, q->left)
			   && isSameNode(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameNode(p, q);
    }
};