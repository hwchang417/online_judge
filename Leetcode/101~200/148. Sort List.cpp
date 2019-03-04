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
    //merge sort on linked list
    ListNode* mergeSort(ListNode* head){
        ListNode *l = NULL, *r = NULL, *lh, *rh, *rs, *ls, *res, *sorted;
        
        if(head == NULL || head->next == NULL)
            return head;
        
        //split into two lists 
        if(head != NULL){
            lh = l = head;
            head = head->next; 
            l->next = NULL;
        }
        
        if(head != NULL){
            rh = r = head;
            head = head->next; 
            r->next = NULL;
        }
        
        while(head != NULL){
            if(head != NULL){
                l->next = head;
                l = l->next;
                head = head->next; 
                l->next = NULL;
            }

            if(head != NULL){
                r->next = head;
                r = r->next;
                head = head->next; 
                r->next = NULL;
            }
        }
        
        //sort two lists individually
        rs = mergeSort(rh);
        ls = mergeSort(lh);
        
        if(rs == NULL){
            return ls;
        }
        
        if(ls == NULL){
            return rs;
        }
        
        if(rs->val > ls->val){
            sorted = ls;
            ls = ls->next;
        }else{
            sorted = rs;
            rs = rs->next;
        }
        
        //when two lists are not null
        res = sorted;
        while(ls != NULL && rs != NULL){
            if(rs->val > ls->val){
                res->next = ls;
                res = res->next;
                ls = ls->next;
            }else{
                res->next = rs;
                res = res->next;
                rs = rs->next;
            }
        }
        
        //directly link all of rest node without if-else check
        while(ls != NULL){
            res->next = ls;
            res = res->next;
            ls = ls->next;
        }
        
        while(rs != NULL){
            res->next = rs;
            res = res->next;
            rs = rs->next;
        }
        
        return sorted;
    }
    
    void bubbleSort(ListNode* head){
        int val;
        ListNode* end, *now;
        
        end = NULL;
        while(end != head){
            now = head;
            while(now->next != end){
                //swap
                if(now->val > now->next->val)
                    val = now->val, now->val = now->next->val, now->next->val = val;
                now = now->next;
            }
            end = now;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        //bubbleSort(head);
        if(head == NULL) return head;
        return mergeSort(head);
    }
};