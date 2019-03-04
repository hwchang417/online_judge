/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    // 1 2 3 4
    // 1 1 2 6
    // 24 12 4 1 
     
    int index, sum;
    int* res;
    
    res = (int*) calloc(sizeof(int), numsSize);
    res[0] = sum = 1;
    
    for(index = 1;index < numsSize;index++){
        sum *= nums[index - 1];
        res[index] = sum;
    }
    
    sum = 1;
    for(index = numsSize - 2;index >= 0;index--){
        sum *= nums[index + 1];
        res[index] *= sum;
    }
    *returnSize = numsSize;
    return res;
}