
#define min(a, b) (a > b ? b : a)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int max_value, row, col, idx;
        vector<int> minTime(N + 1, INT_MAX);
        
        minTime[K] = 0;
        for(idx = 0;idx < N;idx++){
            for(vector<int> n : times){
                int u = n[0], v = n[1], w = n[2];
                if(minTime[u] != INT_MAX && minTime[v] > minTime[u] + w)
                    minTime[v] = minTime[u] + w;
            }
        }
        
        max_value = INT_MIN;
        for(idx = 1;idx <= N;idx++) if(max_value < minTime[idx]) max_value = minTime[idx];
        
        return max_value == INT_MAX ? -1 : max_value;
    }
};