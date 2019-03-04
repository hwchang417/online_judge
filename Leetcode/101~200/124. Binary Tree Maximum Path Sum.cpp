/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MAX(a, b) (a > b ? a : b)
class Solution {
public:
    
    //test case
    //[-1,5,null,4,null,null,2,-4]
    //[-10,9,20,null,null,15,7]
    //[1,2,3]
    //[-3]
    
    //往上回傳path的值有幾種可能性:
    //只回傳自己的node
    //回傳自己在左或右節點的當前node最大值
    
    //單一節點最大值的可能性:
    //左邊獨立的path
    //右邊獨立的Path
    //左右兩邊的path
    //單一節點的node
    
    int maxTree(TreeNode* root, int& max){
        int middle, right, left;
        if(root == NULL)
            return 0;
        
        left = maxTree(root->left, max);
        right = maxTree(root->right, max);
        
        //和0比較，代表不進行連接
        left = MAX(0, left);
        right = MAX(0, right);
        middle = left + right + root->val;
        
        //Path end in middle node
        if(max < middle)
            max = middle;
        
        return root->val + MAX(right, left);
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return INT_MIN;
        int max = root->val;
        int local_max = maxTree(root, max);
        return MAX(max, local_max);
    }
};