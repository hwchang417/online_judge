class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int row, col, size, minValue;
        size = A.size();
        
        for(row = 1;row < size;row++){
            A[row][0] += min(A[row - 1][0], A[row - 1][1]);
            for(col = 1;col < size - 1;col++)
                A[row][col] += min(min(A[row - 1][col - 1], A[row - 1][col]), A[row - 1][col + 1]);
            A[row][size - 1] += min(A[row - 1][size - 1], A[row - 1][size - 2]);
        }
        
        minValue = INT_MAX;
        for(col = 0;col < size;col++)
            if(A[size - 1][col] < minValue) minValue = A[size - 1][col];
                
        return minValue;
    }
};