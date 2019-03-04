class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row, col, rowSize, colSize;
        
        rowSize = matrix.size();
        colSize = matrix[0].size();
        
        for(row = 1;row < rowSize;row++)
            for(col = 1;col < colSize;col++)
                if(matrix[row][col] != matrix[row - 1][col - 1])
                    return false;
        
        return true;
    }
};