/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef struct node{
    int depth, parent;
    TreeNode *node;
}Node;

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int ptr = 0;
        Node ans[2], tmp;
        queue<Node> q;
        
        tmp.node = root; tmp.depth = 0; tmp.parent = INT_MAX;
        q.push(tmp);
        while(!q.empty() && ptr < 2){
            Node n = q.front(); q.pop();
            if(n.node == NULL) continue;
            if(n.node->val == x || n.node->val == y){
                ans[ptr++] = n;
            }
            tmp.depth = n.depth + 1; 
            tmp.parent = n.node->val;
            tmp.node = n.node->left;
            
            q.push(tmp);
            tmp.node = n.node->right;
            q.push(tmp);
        }
        return ans[0].depth == ans[1].depth && ans[0].parent != ans[1].parent;
    }
};