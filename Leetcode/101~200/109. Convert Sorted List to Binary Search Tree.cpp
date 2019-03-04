/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* build(int* arr, int start, int end){
        
        if(start > end) return NULL;
        int middle = (start + end + 1) >> 1;
        TreeNode* root = new TreeNode(arr[middle]);
        root->left = build(arr, start, middle - 1);
        root->right = build(arr, middle + 1, end);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head){
        //find mid node and using its left subtree and right subtree to construct the overall tree
        ListNode* tmp;
        int* arr;
        int index, size = 0;
        
        if(head == NULL) return NULL;
        
        tmp = head;
        while(tmp != NULL)
            size++, tmp = tmp->next;
        
        arr = new int[size];
        
        for(index = 0;index < size;index++)
            arr[index] = head->val, head = head->next;
        
        return build(arr, 0, size - 1);
    }
};