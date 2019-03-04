
#define min(a, b) (a > b ? b : a)
int minSubArrayLen(int s, int* nums, int numsSize) {
    int i, j;
    int min_len, sum;
    
    min_len = INT_MAX;
    for(i = 0;i < numsSize;i++){
        sum = nums[i];
        for(j = i + 1;j < numsSize && sum < s;j++)
            sum += nums[j];
        if(sum >= s)
            min_len = min(min_len, j - i);
    }
    
    return min_len == INT_MAX ? 0 : min_len;
}