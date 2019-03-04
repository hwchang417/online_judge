class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int idx;
        vector<int> t(N + 1, 0);
        vector<bool> s(N + 1, false);
        
        for(vector<int> p : trust)
            t[p[1]]++, s[p[0]] = true;
        
        for(idx = 1;idx <= N;idx++)
            if(t[idx] == N - 1 && !s[idx])
                return idx;
            
        return -1;
    }
};