

class Solution {
public:
    map<int, int> dp;
    inline int min(int num1, int num2){
        return num1 >= num2 ? num2 : num1;
    }

    inline int cost(int d){
        return prev(dp.upper_bound(d))->second;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp = map<int, int>();
        dp.insert({-30, 0});
        for(int d : days){
            dp[d] = min(min(costs[0] + cost(d - 1), 
                        costs[1] + cost(d - 7)),
                        costs[2] + cost(d - 30));
        }
        
        return dp.rbegin()->second;
    }
};