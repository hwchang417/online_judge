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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast, *met;
        slow = fast = head;
        while(slow != NULL && fast != NULL && fast->next != NULL){   
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                met = slow;
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};