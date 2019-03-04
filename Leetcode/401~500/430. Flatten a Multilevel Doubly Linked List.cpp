/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    //如果list有child，則當前的node指向child，child的最後一個指向當前的node的next
    Node* f(Node* head){
        Node *tmp, *prev = NULL;
        
        while(head != NULL){
            if(head->child){
                Node* next = head->next;
                head->next = head->child;
                head->child->prev = head;
                
                tmp = f(head->child);
                
                if(next) next->prev = tmp;
                tmp->next = next;
                
                head->child = NULL;
                prev = tmp;
                head = tmp->next;
            }else{
                prev = head;
                head = head->next;
            }
        }
        return prev;
    }
    
    Node* flatten(Node* head) {
        f(head);
        return head;
    }
};