class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int imax, imin, left, right, numSize;
        numSize = nums.size();
        if(numSize <= 1) return 0;
        
        left = 0; right = numSize - 1;
        while(left < right && nums[left] <= nums[left + 1]) left++;
        if(left == numSize - 1) return 0;
        
        while(nums[right] >= nums[right - 1]) right--;
        
        imax = INT_MIN; imin = INT_MAX;
        for(int range = left;range <= right;range++){
            if(nums[range] > imax) imax = nums[range];
            if(nums[range] < imin) imin = nums[range];
        }
        
        while(left >= 0 && nums[left] > imin) left--;
        while(right <= numSize - 1 && nums[right] < imax) right++;
        
        return right - left - 1;
    }
};