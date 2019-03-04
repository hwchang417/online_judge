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
    ListNode* middleNode(ListNode* head) {
        ListNode* tmp, *middle;
        int len = 0;
        
        if(head == NULL) return head;
        
        //get length of the linked list
        tmp = head;
        while(tmp != NULL)
            len++, tmp = tmp->next;
        
        //get middle of the linked list
        len >>= 1;
        while(len--)
            head = head->next;
        
        return head;
    }
};