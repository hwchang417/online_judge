class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index, size;
        vector<int> res;
        
        size = nums.size();
        for(index = 0;index < size;index++){
            int val = abs(nums[index]) - 1;
            if(nums[val] > 0) nums[val] = - nums[val];
        }
        
        for(index = 0;index < size;index++)
            if(nums[index] > 0)
                res.push_back(index + 1);
        
        return res;
    }
};