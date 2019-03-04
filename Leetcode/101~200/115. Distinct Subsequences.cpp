class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length(), prev, result;
        vector<int> dp(m, 0);
        for(int j = 0; j < n; j++){
            prev = 1;
            for(int i = 0; i < m; i++){
                int temp = dp[i];
                dp[i] = dp[i] + (t[i] == s[j] ? prev : 0);
                prev = temp;
            }
        }
        
        return dp[m - 1];
    }
};  