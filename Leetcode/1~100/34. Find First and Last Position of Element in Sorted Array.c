/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int i;
    int *range, start, end;
    
    range = (int*)malloc(sizeof(int) * 2);
    range[0] = range[1] = -1;
    start = end = -1;
    i = *returnSize = 0;
    
    while(i < numsSize){
        if(nums[i] == target && start == -1){ 
            start = i;
            end = i;
            break;
        }
        i++;
    }
    
    while(i < numsSize){
        if(nums[i] != target){ 
            end = i - 1;
            break;
        }
        end = i;
        i++;
    }
    
    *returnSize = 2;
    if(i == numsSize && (start == -1 || end == -1)){
        return range;
    }
    
    range[0] = start;
    range[1] = end;
    
    return range;
}
