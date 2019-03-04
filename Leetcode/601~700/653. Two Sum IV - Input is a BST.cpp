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
    bool findTarget(TreeNode* root, int k) {
        map<int, bool> m;
        queue<TreeNode*> q;
        
        if(root == NULL) return false;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(m.find(node->val) != m.end())
                return true;
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
            m[k - node->val] = true;
        }
        
        return false;
    }
};