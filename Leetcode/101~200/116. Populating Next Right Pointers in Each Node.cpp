/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void preorderTraversal(vector<TreeLinkNode*>& levels, TreeLinkNode* root, int depth){
        if(root == NULL) return;
        
        if(levels.size() == depth){
            levels.push_back(root);
        }else{
            levels[depth]->next = root;
            levels[depth] = root;
        }
        
        preorderTraversal(levels, root->left, depth + 1);
        preorderTraversal(levels, root->right, depth + 1);
    }
    
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> levels;
        
        preorderTraversal(levels, root, 0);
        
        for(TreeLinkNode* r : levels)
            r->next = NULL;
    }
};