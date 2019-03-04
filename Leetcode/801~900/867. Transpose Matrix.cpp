class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row, col;
        vector<vector<int>> res(A[0].size(), vector<int>(A.size(), 0));
        
        for(row = 0;row < A.size();row++)
            for(col = 0;col < A[0].size();col++)
                res[col][row] = A[row][col];
        
        return res;
    }
};