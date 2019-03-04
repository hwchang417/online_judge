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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //let q greater than p
        if(p->val < q->val)
            return lowestCommonAncestor(root, q, p);
        
        while(root != NULL){
            if(root->val <= p->val && root->val >= q->val)
                return root;
            else if(root->val < q->val)
                root = root->right;
            else
                root = root->left;
        }
        
        return root;
    }
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while(root != NULL){
            if(root->val > p->val && root->val > q->val)
                root = root->left;
            else if(root->val < p->val && root->val < q->val)
                root = root->right;
            else
                return root;
        }
        
        return root;
    }
};