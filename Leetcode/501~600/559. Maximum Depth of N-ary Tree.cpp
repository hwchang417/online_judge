/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#define max(num1, num2) (num1 > num2 ? num1 : num2)
class Solution {
public:
    void dfs(Node* root, int *maximum, int depth){
        if(root == NULL) return;
        *maximum = max(*maximum, depth);
        for(Node *node : root->children)
            dfs(node, maximum, depth + 1);
    }
    
    int maxDepth(Node* root) {
        int maximum = 0;
        dfs(root, &maximum, 1);
        return maximum;
    }
};