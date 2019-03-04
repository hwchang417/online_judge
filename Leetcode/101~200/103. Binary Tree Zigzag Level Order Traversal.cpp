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
    
    void zigzagSearch(vector<vector<int>>& res, TreeNode* root, int depth){
        if(root == NULL) return;
        if(res.size() <= depth) res.push_back(vector<int>());
        res[depth].push_back(root->val);
        zigzagSearch(res, root->left, depth + 1);
        zigzagSearch(res, root->right, depth + 1);
    }
    
    void swapVec(vector<int>& res){
        int head, tail, size_2, tmp;
        tail = res.size();
        size_2 = tail >> 1;
        tail--;
        for(head = 0;head < size_2;head++, tail--){
            tmp = res[tail];
            res[tail] = res[head];
            res[head] = tmp;
        }
    }
    
    void reverseEvenArray(vector<vector<int>>& res){
        int index, size;
        size = res.size();
        for(index = 1;index < size;index+=2){
            //swap
            swapVec(res[index]);
        }
        
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagSearch(res, root, 0);
        reverseEvenArray(res);
        
        return res;
    }
};