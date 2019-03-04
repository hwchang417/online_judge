class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int index, size, cnt, max;
        
        size = nums.size();
        if(size == 0) return 0;
        
        sort(nums.begin(), nums.end());
        max = cnt = 1;
        for(index = 1;index < size;index++){
            if(nums[index] == nums[index - 1] + 1){
                cnt++;
                if(cnt > max) max = cnt;
            }else if(nums[index] != nums[index - 1])
                cnt = 1;
        }
        
        return max;
    }
};