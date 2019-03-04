class Solution {
public:
    
    int triangleNumber(vector<int>& nums) {
        int index, cnt, l, r;
        cnt = 0;
        sort(nums.begin(), nums.end());
        
        for(index = nums.size() - 1;index >= 0;index--){
            l = 0;
            r = index - 1;
            while(l < r){
                if(nums[l] + nums[r] > nums[index])
                    cnt += (r - l), r--;
                else
                    l++;
            }
        }
        
        return cnt;
    }
};