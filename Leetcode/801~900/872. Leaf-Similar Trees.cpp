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
    void traversal(TreeNode* root, vector<int>& v){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
            return;
        }
        
        traversal(root->left, v);
        traversal(root->right, v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        int index, size1, size2;
        vector<int> v1, v2;
        
        traversal(root1, v1);
        traversal(root2, v2);
        
        size1 = v1.size();
        size2 = v2.size();
        
        if(size1 != size2)
            return false;
        
        for(index = 0;index < size1;index++)
            if(v1[index] != v2[index])
                return false;
                
        return true;
    }
};