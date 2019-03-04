class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int index, size, prev, repeat;
        vector<int> res;
        
        size = nums.size();
        if(size == 0) return res;
        
        sort(nums.begin(), nums.end());
        
        repeat = 0;
        prev = nums[0];
        for(index = 1;index < size;index++){
            if(prev == nums[index])
                repeat++;
            else if(repeat < 1)
                res.push_back(prev);
            else
                repeat = 0;
            
            prev = nums[index];
        }
        
        if(repeat == 0)
            res.push_back(prev);
        
        return res;
    }
};