int removeDuplicates(int* nums, int numsSize) {
    int index;
    int tail = 0;
    for(index = 1;index < numsSize;index++){
        if(nums[index] != nums[index - 1])
            tail++;
        nums[tail] = nums[index];
    }
    return numsSize >= 1 ? tail + 1 : tail;
}