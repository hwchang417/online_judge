/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *h, *tmp;
    struct ListNode *first, *second;
    int i;
    dummy->next = head;
    h = head;
    first = second = dummy;
    for(i = -1;i < n;i++){
        first = first->next;
    }
    while(first != NULL){
        first = first->next;
        second = second->next;
    }
    tmp = second->next->next;
    second->next = tmp;
    return dummy->next;
}