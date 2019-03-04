int removeElement(int* nums, int numsSize, int val) {
    int index;
    int tail = 0;
    for(index = 0;index < numsSize;index++){
        if(nums[index] != val){
            nums[tail++] = nums[index];
        }
    }
    return tail;
}