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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int cnt, size = lists.size(), i, j;
        int *val;
        ListNode *node = NULL, *list, *head, *tmp;
        cnt = 0;
        
        for(i = 0;i < size;i++){
            node = lists[i];
            while(node != NULL) node = node->next, cnt++;
        }
        
        if(cnt == 0) return NULL;
        
        val = (int*)malloc(sizeof(int) * (cnt));
        
        for(i = 0, j = 0;i < size;i++){
            node = lists[i];
            while(node != NULL) val[j++] = node->val, node = node->next;
        }
        
        sort(val, val + cnt);
        
        list = new ListNode(0);
        list->val = val[0];
        head = list;
        for(i = 1;i < cnt;i++){
            list->next = new ListNode(0);
            list = list->next;
            list->val = val[i];
        }
        
        list->next = NULL;
        
        free(val);
        
        return head;
    }
};