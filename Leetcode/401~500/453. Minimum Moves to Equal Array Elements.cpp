class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, min = INT_MAX;
        
        for(int n : nums){
            if(min > n) min = n;
            sum += n;
        }
        
        return sum - min * nums.size();
    }
};