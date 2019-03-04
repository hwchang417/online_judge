/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* tmp = head;
    struct ListNode* first, *second, *third = NULL, *pre_first = NULL;
    
    first = head;
    tmp = (head != NULL && head->next != NULL) ? head->next : head;
    while(head != NULL && head->next != NULL){
        first = head;
        second = head->next;
        third = second->next;
        
        second->next = first;
        if(pre_first != NULL) pre_first->next = second;
        
        head = third;
        pre_first = first;
    }
    if(head != NULL ){
        first->next = third;
    }else if(first != NULL) first->next = NULL;
    
    return tmp;
}