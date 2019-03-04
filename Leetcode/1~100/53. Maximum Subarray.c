int maxSubArray(int* nums, int numsSize) {
    int i, sum, max_sum;
    sum = 0;
    max_sum = nums[0];
    for(i = 0;i < numsSize;i++){
        sum += nums[i];
        if(max_sum < sum)
            max_sum = sum;
        if(sum < 0)
            sum = 0;
    }
    
    return max_sum;
}