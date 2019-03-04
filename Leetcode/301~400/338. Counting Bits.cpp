class Solution {
public:
    vector<int> countBits(int num) {
        int idx, cnt;
        vector<int> res(1, 0);
        
        for(idx = 1;idx <= num;idx++){
            if((idx & (idx - 1)) == 0)
                cnt = 0;
            res.push_back(res[cnt++] + 1);
        }
        
        return res;
    }
};