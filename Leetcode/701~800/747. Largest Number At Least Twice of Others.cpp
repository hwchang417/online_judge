class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx, max_idx, max_value;
        
        if(nums.size() == 0) return -1;
        
        max_idx = 0;
        max_value = nums[0];
        for(idx = 1;idx < nums.size();idx++){
            if(max_value < nums[idx]){
                max_idx = idx;
                max_value = nums[idx];
            }
        }
        
        for(idx = 0;idx < nums.size();idx++)
            if(idx != max_idx && max_value < (nums[idx] << 1))
                return -1;
        
        return max_idx;
    }
};