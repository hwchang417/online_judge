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
    
    void traversal(vector<int>& max, vector<int>& min, TreeNode* root, int dep, int num){
        if(dep >= max.size()){
            max.push_back(num);
            min.push_back(num);
        }else{
            if(max[dep] < num) max[dep] = num;
            if(min[dep] > num) min[dep] = num;
        }
        if(root->left != NULL) traversal(max, min, root->left, dep + 1, (num << 1));
        if(root->right != NULL) traversal(max, min, root->right, dep + 1, (num << 1) + 1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        //分成 depth 和 number
        //對每一層的數字做最大值、最小值的判斷
        //1
        //2,3
        //4,5 6,7
        //8,9 10,11 12,13 14,15
        int index, size, max_width;
        vector<int> max, min;
        max_width = 0;
        
        if(root == NULL) return max_width;
        traversal(max, min, root, 0, 1);
        
        size = max.size();
        for(index = 0;index < size;index++)
            if(max_width < max[index] - min[index])
                max_width = max[index] - min[index];
        
        return max_width + 1;
    }
};