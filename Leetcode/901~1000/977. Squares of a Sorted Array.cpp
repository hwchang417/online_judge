class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i;
        vector<int> res(A.size());
        
        i = 0;
        for(int n : A)
            res[i++] = n * n;
        
        sort(res.begin(), res.end());
        
        return res;
    }
};