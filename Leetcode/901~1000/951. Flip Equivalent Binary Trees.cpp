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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2){
            if(root1->val != root2->val)
                return false;
            
            //判斷兩個的subtree是不是一樣，或者經過交換後一樣
            return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
                   (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
        }else if(!root1 && !root2)
            return true;
        return false;
    }
};