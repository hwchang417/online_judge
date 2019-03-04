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
class Solution {
public:
    
    void postorder(vector<int>& res, Node* root){
        if(root == NULL) return;
        for(Node* n : root->children)
            if(n) postorder(res, n);
        res.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(res, root);
        return res;
    }
};