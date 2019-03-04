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
    void preorder(vector<int>& res, Node* root){
        if(root == NULL) return;
        res.push_back(root->val);
        for(Node* n : root->children)
            if(n) preorder(res, n);
    }
    
    vector<int> preorder(Node* root) {
        int size, index;
        stack<Node*> s;
        vector<int> res;
        
        if(root == NULL) return res;
        
        s.push(root);
        while(!s.empty()){
            Node* n = s.top();
            s.pop();
            if(n == NULL) continue;
            res.push_back(n->val);
            size = n->children.size();
            for(index = size - 1;index >= 0;index--)
                s.push(n->children[index]);
        }
        
        return res;
    }
};