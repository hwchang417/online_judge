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
    bool hasCycle(ListNode *head) {
        ListNode *now = head, *pre = head;

        while(now != NULL){
            if(now->next == head) return true;
            now = now->next;
            pre->next = head;
            pre = now;
        }
        return false;
    }
};