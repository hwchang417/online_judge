class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index, size;
        size = nums.size();
        
        if(size == 0) return -1;
        
        if(size == 1 || nums[0] > nums[1])
            return 0;
        
        if(nums[size - 1] > nums[size - 2])
            return size - 1;
        
        for(index = 1;index < size - 1;index++){
            if(nums[index] > nums[index - 1] && nums[index] > nums[index + 1]){
                return index;
            }
        }
        
        
        return -1;
    }
};