class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int col, row, up, down, colSize, rowSize;
        
        //上下鏡射
        up = 0; down = matrix.size() - 1;
        rowSize = matrix.size();
        colSize = matrix[0].size();
        while(up < down){
            for(col = 0;col < colSize;col++)
                matrix[up][col] = matrix[up][col] ^ matrix[down][col] ^ (matrix[down][col] = matrix[up][col]);
            up++;
            down--;
        }
        
        //row和col對調
        for(row = 0;row < rowSize;row++)
            for(col = row;col < colSize;col++)
                matrix[row][col] = matrix[row][col] ^ matrix[col][row] ^ (matrix[col][row] = matrix[row][col]);
        
    }
};