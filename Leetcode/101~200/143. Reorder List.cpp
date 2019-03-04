/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* first, *second, *tmp;
        
        if(head == NULL) return;
        
        first = head;
        while(first != NULL){
            s.push(first);
            first = first->next;
        }
        
        first = head; second = NULL;
        while(!s.empty()){
            second = s.top();
            s.pop();
            if(first->next == second || first == second)
                break;
            tmp = first->next;
            first->next = second;
            second->next = tmp;
            
            second = second->next;
            first = tmp;
        }
        
        if(first->next == second){
            first->next->next = NULL;
        }else if(first == second){
            first->next = NULL;
        }
    }
};