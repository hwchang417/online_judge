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
    
    void recover(TreeNode* r, TreeNode* &prev, TreeNode* &a, TreeNode* &b){
        if(r){
            recover(r->left, prev, a, b);
            
            if(r->val < prev->val){
                if(!a) a = prev;
                b = r;
            }
            prev = r;
            
            recover(r->right, prev, a, b);
        }
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode p(INT_MIN);
        TreeNode *a = NULL, *b = NULL, *prev = &p;
        recover(root, prev, a, b);
        
        if(a && b){
            int tmp = a->val;
            a->val = b->val;
            b->val = tmp;
        }
    }
};