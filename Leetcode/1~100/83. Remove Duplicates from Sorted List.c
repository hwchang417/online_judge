/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* add(int value){
	struct ListNode* list;
	
	list = (struct ListNode*)malloc(sizeof(struct ListNode));
	
	if(list == NULL)
		return list;
	
	list->val = value;
	list->next = NULL;
	
	return list;
}
 
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode* res, *tmp;
    int prev;
    
    if(head == NULL)
  		return head;
  		
    prev = head->val;
    tmp = res = add(prev);
    head = head->next;
    while(head != NULL){
    	if(prev != head->val){
    		tmp->next = add(head->val);
    		tmp = tmp->next;
		}
		prev = head->val;
    	head = head->next;
	}
    return res;
}