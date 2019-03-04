class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int index, start, size, tmp, cnt, max;
        
        max = INT_MIN;
        size = nums.size();
        for(index = 0;index < size;index++){
            cnt = 0;
            start = index;
            while(nums[start] != -1)
                tmp = start, start = nums[start], nums[tmp] = -1, cnt++;
            if(cnt > max) max = cnt;
        }
        
        return max;
    }
};