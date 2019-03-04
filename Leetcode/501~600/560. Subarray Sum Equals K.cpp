class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int acc, cnt;
        unordered_map<int, int> prefix_sum;
        
        prefix_sum[0] = 1; cnt = acc = 0;
        for(int n : nums){
            acc += n;
            cnt += prefix_sum[acc - k];
            prefix_sum[acc]++;
        }
        return cnt;
    }
};