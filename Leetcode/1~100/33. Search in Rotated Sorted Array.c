int search(int* nums, int numsSize, int target) {
    int i;
    int prev = nums[0];
    int ascending = 0;
    
    for(i = 1;i < numsSize;i++){
        if(prev == target){
            return i - 1;
        }
        //if it is in rotated point and less than target, it would be impossible to search target
        if(prev > nums[i] && nums[i] > target){
            return -1;
        }
        prev = nums[i];
    }
    
    return nums[i - 1] == target ? i - 1 : -1;
}