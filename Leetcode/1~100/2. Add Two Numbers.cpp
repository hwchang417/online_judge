/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p1, *p2, *p3;
    int carry = 0;
    l3->next = NULL;
    l3->val = 0;
    
    p1 = l1;
    p2 = l2;
    p3 = l3;
    for(;p1 != NULL || p2 != NULL;){
        if(p1 != NULL){
            carry += p1->val;
            p1 = p1->next;
        }
        if(p2 != NULL){
            carry += p2->val;
            p2 = p2->next;
        }
        
        if(carry >= 10){
            p3->val = carry - 10;
            p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            carry = p3->next->val = 1;
        }else{
            p3->val = carry;
            if(p1 != NULL || p2 != NULL){
                p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                carry = 0;
            }else break;
        }
        
        p3 = p3->next;
    }
    p3->next = NULL;
    return l3;
}