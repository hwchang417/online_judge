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
    int numComponents(ListNode* head, vector<int>& G) {
        int cnt = 0, flag = 0;
        bool lookup[10001] = {false};
        
        for(int g : G) lookup[g] = true;
        
        while(head != NULL){
            if(lookup[head->val])
                flag = 1;
            else if(flag)
                cnt++, flag = 0;
            head = head->next;
        }
        return (flag == 1) ? cnt + 1 : cnt;
    }
};