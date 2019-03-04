class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int i, size;
        int mini, minj;
        
        size = ops.size();
        
        if(size == 0) return m * n;
        
        mini = minj = INT_MAX;
        for(i = 0;i < size;i++){
            if(mini > ops[i][0]) mini = ops[i][0];
            if(minj > ops[i][1]) minj = ops[i][1];
        }
        
        return mini * minj;
    }
};