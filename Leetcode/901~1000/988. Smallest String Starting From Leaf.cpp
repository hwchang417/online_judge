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
    
    vector<string> dfs(TreeNode *root){
        string curr;
        vector<string> ret, left, right;
        if(root == NULL) return ret;
        curr = root->val + 'a';
        left = dfs(root->left);
        right = dfs(root->right);
        for(string str : left) ret.push_back(str + curr);
        for(string str : right) ret.push_back(str + curr);
        if(ret.size() == 0) ret.push_back(curr);
        return ret;
    } 
    
    string smallestFromLeaf(TreeNode* root) {
        string min;
        vector<string> strings;
        if(root == NULL) return min;
        
        strings = dfs(root);
        min = strings[0];
        for(string str : strings)
            if(str < min) min = str;
        return min;
    }
};