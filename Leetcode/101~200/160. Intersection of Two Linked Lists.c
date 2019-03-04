/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tmpA = headA, *tmpB = headB;
    
    if(headA == NULL || headB == NULL) return NULL;
    
    while(headA != NULL || headB != NULL){
        
        if(headA == NULL) headA = tmpB;
        if(headB == NULL) headB = tmpA;
        
        if(headA->val == headB->val) return headA;
        
        headA = headA->next;
        headB = headB->next;
    }
    
    return NULL;
}