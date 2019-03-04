
bool search(int* nums, int numsSize, int target) {
	int i, j, start, end;
	int sindex, eindex, mindex, mnum;
    int res;
    
    if(nums == NULL || numsSize == 0) return false;
    
    //detect rotation count in array
	for(i = 0;i < numsSize - 1;i++)
		if(nums[i] > nums[i + 1])
			break;
    end = i;
    start = (i + 1) % numsSize;
    
    sindex = 0;
    eindex = numsSize - 1;
    while(sindex <= eindex){
    	mindex = (sindex + eindex) >> 1;
    	mnum = nums[(mindex + start) % numsSize];
    	if(mnum == target){
    		return true;
		}else if(mnum < target){
			sindex = mindex + 1;
		}else{
			eindex = mindex - 1;
		}
	}
    
    return false;
}
