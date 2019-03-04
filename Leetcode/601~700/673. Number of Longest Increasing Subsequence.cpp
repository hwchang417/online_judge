class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int i, j, size, max, cnt;
        vector<int> len(nums.size(), 1);
        vector<int> num(nums.size(), 1);
        
        if(nums.size() == 0) return nums.size();
        
        max = 1;
        cnt = 1;
        size = nums.size();
        for(i = 1;i < size;i++){
            for(j = 0;j < i;j++)
                if(nums[i] > nums[j]){
                    if(len[j] + 1 > len[i]){
                        len[i] = len[j] + 1;
                        num[i] = num[j];
                    }
                    else if(len[j] + 1 == len[i])
                        num[i] += num[j];
                }
            
            if(len[i] > max){
                max = len[i];
                cnt = num[i];
            }else if(len[i] == max){
                cnt += num[i];
            }
        }
        return cnt;
    }
};