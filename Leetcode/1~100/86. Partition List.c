
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* h1, *h2;
    struct ListNode* d1, *d2;
    
    if(head == NULL) return head;
    
    d1 = h1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    d2 = h2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    while(head != NULL){
    	if(head->val < x){
    		h1->next = head;
    		h1 = h1->next;
		}else{
			h2->next = head;
			h2 = h2->next;
		}
    	head = head->next;
	}
	
    h2->next = NULL;//
	h1->next = d2->next;
    h1 = d1->next;
    
    free(d1);
    free(d2);
    
    return h1;
}
