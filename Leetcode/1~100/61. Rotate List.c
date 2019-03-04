/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int i, size;
	struct ListNode* result;
    struct ListNode* node;
    
    if(head == NULL || k == 0)
    	return head;
    
    //list size
    size = 1;
    node = head;
    while(node->next != NULL){
   		node = node->next;
    	size++;
	}
	
	node->next = head;
	k = size - (k % size);
	for(i = 0;i < k;i++){
		node = node->next;
	}
	
	result = node->next;
	node->next = NULL;
    return result;
}