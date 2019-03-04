class Solution {
public:
    
    vector<int> shortestToChar(string S, char C) {
        int left, right, curr, size = S.size(), cnt;
        vector<int> res(size, INT_MAX);
        
        for(curr = 0;curr < size && S[curr] != C;curr++);
        
        for(;curr < size;curr++){
            if(S[curr] == C)
                cnt = 0;
            else
                cnt++;
            res[curr] = cnt;
        }
        
        for(curr = size - 1;curr >= 0;curr--){
            if(S[curr] == C)
                cnt = 0;
            else{
                cnt++;
                res[curr] = min(res[curr], cnt);
            }
        }
        
        return res;
    }
};