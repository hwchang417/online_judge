class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int idx;
        string res(S.size(), 0);
        unsigned long long rotation, times;
        
        times = 0;
        for(idx = shifts.size() - 1;idx >= 0;idx--){
            times += shifts[idx];
            rotation = (S[idx] + times - 'a');
            res[idx] = (rotation % 26) + 'a';
        }
        
        return res;
    }
};