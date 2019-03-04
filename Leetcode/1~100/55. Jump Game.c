
bool canJump(int* nums, int numsSize) {
    int i, max, tmp;
    
	max = 0;
    for(i = 0;i < numsSize - 1;i++){
    	tmp = nums[i] + i;
    	if(i > max || max >= numsSize - 1)
			break;
    	if(max < tmp)
    		max = tmp;
	}
    return max >= numsSize - 1;
}