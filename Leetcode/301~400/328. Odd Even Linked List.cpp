class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int count;
        ListNode podd(0), peven(0);
        ListNode* odd, *even;
        
        odd = &podd;
        even = &peven;
        count = 1;
        while(head != NULL){
            if(count & 0x01) odd->next = head, odd = odd->next;
            else even->next = head, even = even->next;
            head = head->next;
            count++;
        }
        odd->next = peven.next;
        even->next = NULL;
        
        return podd.next;
    }
};