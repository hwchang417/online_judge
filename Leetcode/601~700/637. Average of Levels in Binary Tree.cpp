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
    
    void summation(TreeNode* root, vector<int>& cnt, vector<double>& res, int dep){
        
        if(root == NULL) return;
        
        if(cnt.size() < dep){
            cnt.push_back(1);
            res.push_back((double)root->val);
        }else{
            cnt[dep - 1] ++;
            res[dep - 1] += (double)root->val;
        }
        summation(root->right, cnt, res, dep + 1);
        summation(root->left, cnt, res, dep + 1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        int index;
        vector<int> cnt;
        vector<double> res;
        summation(root, cnt, res, 1);
        for(index = 0;index < cnt.size();index++)
            res[index] /= cnt[index];
        return res;
    }
};