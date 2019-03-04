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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev, *next;
        
        prev = NULL;
        next = head;
        
        //remove Elements from head
        while(next != NULL && next->val == val){ 
            head = next->next;
            free(next);
            next = head;
        }
        
        //remove Elements inside linked list
        while(next != NULL){
            if(next->val == val){
                prev->next = next->next;
                free(next);
                next = prev->next;
            }else{
                prev = next;
                next = next->next;
            }
        }
        
        return head;
    }
};