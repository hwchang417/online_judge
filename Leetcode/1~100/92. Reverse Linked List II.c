/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    int i;
    struct ListNode dump;
	struct ListNode *tmp, *start, *next = NULL;
	
	dump.next = head;
	start = &dump;
	i = 1;
	while(i < m) start = start->next, head = head->next, i++;
	
	while(head != NULL && n-- >= m){
		tmp = head->next;
		head->next = next;
		next = head;
		head = tmp;
	}
	start->next->next = tmp;
	start->next = next;
	
	return m == 1 ? next : dump.next;
}