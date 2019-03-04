/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int i, j, first;
    struct ListNode *tmp, *tail;
    struct ListNode *thead = head; //temp head
    struct ListNode **ptr = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);
    if(!ptr) return NULL;
    first = 0;
    while(head != NULL){
        tmp = head;
        for(i = 0;i < k && head != NULL;i++){
            ptr[i] = head;
            head = head->next;
        }
        if(i == k){
            for(j = k - 1;j >= 1;j--)
                ptr[j]->next = ptr[j - 1];
            if(!first) thead = ptr[k - 1], first = 1;
            else tail->next = ptr[k - 1];
        }else if(first) tail->next = tmp;
        tail = ptr[0]; //first one
    }
    if(i == k) tail->next = NULL;
    free(ptr);
    
    return thead;
}