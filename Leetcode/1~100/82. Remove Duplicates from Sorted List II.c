 
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode* res, *tmp, *nlist;
    int prev, flag;
    
	res = tmp = NULL;
    while(head != NULL){
    	if(head->next && head->val == head->next->val){
    		prev = head->val;
    		while(head && head->val == prev)
	    		head = head->next;
		}else{
			nlist = (struct ListNode*)malloc(sizeof(struct ListNode));
			
			if(nlist == NULL)
				return nlist;
			
			nlist->val = head->val;
			nlist->next = NULL;
	
			if(res != NULL){
				tmp->next = nlist;
				tmp = tmp->next;
			}else{
				res = tmp = nlist;
			} 
			head = head->next;
		}
	}
    return res;
}