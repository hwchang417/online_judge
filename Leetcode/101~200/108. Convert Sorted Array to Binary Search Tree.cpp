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
    TreeNode* constructTree(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        TreeNode* root;
        int m = (l + r + 1) >> 1;
        root = new TreeNode(nums[m]);
        root->left = constructTree(nums, l, m - 1);
        root->right = constructTree(nums, m + 1, r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return constructTree(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBST2(vector<int>& nums) {
        
        if(nums.size() == 0) return NULL;
        
        TreeNode* root;
        root = new TreeNode(0);
        constructTree2(nums, root, 0, nums.size() - 1);
        
        return root;
    }
    
    void constructTree2(vector<int>& nums, TreeNode* root, int l, int r){
        int m = (l + r + 1) >> 1;
        
        root->val = nums[m];
        
        if(m != r){
            root->right = new TreeNode(0);
            constructTree2(nums, root->right, m + 1, r);
        }
        
        if(m != l){
            root->left = new TreeNode(0);
            constructTree2(nums, root->left, l, m - 1);
        }
    }
    
};