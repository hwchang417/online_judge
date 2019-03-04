class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int idx;        
        for(idx = 2;idx < cost.size();idx++)
            cost[idx] += min(cost[idx - 1], cost[idx - 2]);
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};