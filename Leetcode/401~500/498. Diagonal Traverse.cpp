#define isInsideBoundary(x, size) (x >= 0 && x < size)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int x, y, rowSize, colSize;
        vector<int> res;
        if((rowSize = matrix.size()) == 0 || (colSize = matrix[0].size()) == 0) return res;
        
        x = y = 0;
        while(x < colSize - 1 || y < rowSize - 1){
            res.push_back(matrix[y][x]);
            if(((y + x) & 0x01) == 0){
                if(y == 0 || x == colSize - 1){
                    if(x != colSize - 1) x++;
                    else y++;
                }else{
                    x++;
                    y--;
                }
            }else{
                if(x == 0 || y == rowSize - 1){
                    if(y != rowSize - 1) y++;
                    else x++;
                }else{
                    x--;
                    y++;
                }
            }
        }
        
        if(x == colSize - 1 && y == rowSize - 1)
            res.push_back(matrix[y][x]);
        
        return res;
    }
};