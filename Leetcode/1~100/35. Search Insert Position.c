int searchInsert(int* nums, int numsSize, int target) {
    
    if(numsSize == 0) return 0;
    if(nums[0] >= target) return 0;
    if(nums[numsSize - 1] < target) return numsSize;
    
    int start = 1, end = numsSize - 1, mid;
    
    while(start + 1 < end){
        mid = (start + end) >> 1;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            start = mid + 1;
        }else if(nums[mid] > target){
            end = mid - 1;
        }
    }
    
    if(nums[start] >= target){
        return start;
    }else if(nums[end] >= target){
        return end;
    }else{
        return end + 1;
    }
}