/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* first, *prev, *newList, *oldList, *tmp, *tmp2;
        ListNode* print;
        if(head == NULL)
            return head;
        
        first = newList = head;
        oldList = head->next;
        newList->next = NULL;
        while(oldList != NULL){
            prev = first = newList;
            while(newList != NULL && oldList->val > newList->val){
                prev = newList;
                newList = newList->next;
            }
            
            if(newList == NULL){ //oldList->val > newList->val
                tmp = oldList->next;
                newList = first;
                prev->next = oldList;
                oldList->next = NULL;
                oldList = tmp;
            }else if(first == newList){//oldList->val < newList->val
                tmp = oldList->next;
                oldList->next = first;
                first = newList = oldList;
                oldList = tmp;
            }else{ //oldList->val 在中間
                prev->next = oldList;
                tmp = oldList->next;
                oldList->next = newList;
                newList = first;
                oldList = tmp;
            }
            
        }
        return first;
    }
};