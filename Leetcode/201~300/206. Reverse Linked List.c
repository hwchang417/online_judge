
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev, *next, *tmp;
    
    if(head == NULL || head->next == NULL) return head;
    
    prev = NULL;
    next = head;
    while(next != NULL){
    	tmp = next->next;
    	next->next = prev;
    	prev = next;
    	next = tmp;
	}
    
    return prev;
}