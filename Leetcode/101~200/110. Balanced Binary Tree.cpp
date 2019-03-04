/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define max(a, b) (a > b ? a : b)
class Solution {
public:
    //return d - 1 if the node is null
    //如果node是null，回傳上一層的深度 d - 1
    //如果兩個節點都是null，則這一層的d就是該子樹的深度
    //左右層的深度差，如果超過1，則回傳-1
    //重構技巧調換順序
    //
    //    int left = depth(root->left, d + 1);
    //    int right = depth(root->right, d + 1);
    //    if(left == -1 || right == -1)
    //        return -1;
    //
    //    int left = depth(root->left, d + 1);
    //    if(left == -1)  return -1;
    //    int right = depth(root->right, d + 1);
    //    if(right == -1) return -1;
    //
    //
    int depth(TreeNode* root, int d){
        
        if(root == NULL) return d - 1;
        
        if(root->left == NULL && root->right == NULL)
            return d;
        
        int left = depth(root->left, d + 1);
        if(left == -1)  return -1;
        int right = depth(root->right, d + 1);
        if(right == -1) return -1;
        
        
        return abs(left - right) > 1 ? -1 : max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return depth(root, 0) != -1;
    }
};
