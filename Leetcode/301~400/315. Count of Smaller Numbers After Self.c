/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Listnode{
    long long int val;
    struct Listnode* next;
};

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    struct Listnode* head = NULL, *tmp, *prev;
    int index, *res;
    
    if(numsSize == 0) return NULL;
    
    res = (int*) malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    res[numsSize - 1] = 0;
    
    tmp = head = (struct Listnode*) malloc(sizeof(struct Listnode));
    head->val = nums[numsSize - 1];
    head->next = NULL;
    
    for(index = numsSize - 2;index >= 0;index--){
        int cnt = 0;
        prev = NULL;
        tmp = head;
        while(tmp != NULL && tmp->val < nums[index])
            prev = tmp, tmp = tmp->next, cnt++;
        
        if(prev == NULL){
            tmp = (struct Listnode*) malloc(sizeof(struct Listnode));
            tmp->val = nums[index];
            tmp->next = head;
            head = tmp;
        }else{
            struct Listnode* newNode = (struct Listnode*) malloc(sizeof(struct Listnode));
            newNode->val = nums[index];
            newNode->next = tmp;
            prev->next = newNode;
        }
        
        res[index] = cnt;
    }
    
    while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
    
    return res;
}
