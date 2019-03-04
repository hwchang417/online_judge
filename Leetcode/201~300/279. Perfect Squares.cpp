class Solution {
public:
    int numSquares(int n) {
        int index, squ, tmp;
        vector<int> dp(1, 0);
        for(index = 1;index <= n;index++){
            dp.push_back(INT_MAX);
            for(squ = 1;(tmp = squ * squ) <= index;squ++)
                dp[index] = min(dp[index], dp[index - tmp] + 1);
        }
        return dp[n];
    }
};