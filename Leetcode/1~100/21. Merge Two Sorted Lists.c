/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3, *head = NULL;
    struct ListNode **tmp;
    int flag = 0;
    
    if(l1 == NULL && l2 == NULL) return head;
    
    l3 = (struct ListNode*) malloc(sizeof(struct ListNode));
    head = l3;
    
    while(l1 != NULL && l2 != NULL){
        if(flag){ 
            l3->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            l3 = l3->next;
        }
        
        l3->next = NULL;
        
        if(l1->val > l2->val){
            l3->val = l2->val;
            l2 = l2->next;
        }else{
            l3->val = l1->val;
            l1 = l1->next;
        }
        
        flag = 1;
    }
    
    tmp = (l1 == NULL) ? &l2 : &l1;
    
    while((*tmp) != NULL){
        if(flag){ 
            l3->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            l3 = l3->next;
        }
        
        l3->next = NULL;
        l3->val = (*tmp)->val;
        (*tmp) = (*tmp)->next;
        
        flag = 1;
    }
    
    return head;
}