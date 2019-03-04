class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int index, size;
        vector<int> res;
        
        size = nums.size();
        for(index = 0;index < size;index++)
            while(nums[index] != index + 1 && nums[index] != nums[nums[index] - 1])
                swap(nums[index], nums[nums[index] - 1]);
        
        for(index = 0;index < size;index++)
            if(nums[index] != index + 1)
                res.push_back(nums[index]);
            
        return res;
    }
};