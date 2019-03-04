int missingNumber(int* nums, int numsSize) {
    int index, sum;
    sum = 0;
    for(index = 0;index < numsSize;index++){
        sum ^= nums[index];
        sum ^= index;
    }
    sum ^= index;
    return sum;
}