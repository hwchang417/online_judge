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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root){
            queue<TreeNode*> q;
            queue<int> d;
            d.push(0);
            q.push(root);
            while(!q.empty()){
                TreeNode* cur = q.front();
                int dep = d.front();
                q.pop(); d.pop();
                if(cur->left != NULL){  q.push(cur->left), d.push(dep + 1);}
                if(cur->right != NULL){  q.push(cur->right), d.push(dep + 1);}
                
                if(res.size() <= dep) res.push_back(vector<int>());
                res[dep].push_back(cur->val);
            }   
        }
        return res;
    }
};