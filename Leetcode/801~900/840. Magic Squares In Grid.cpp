class Solution {
public:
    
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int i, j, m, n, y, x, nth;
        int sum, prev_sum;
        int rowSize, colSize, mcnt;
        
        const int row[8][3] = {{0, 0, 0}, {1, 1, 1}, {2, 2, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
        const int col[8][3] = {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 0, 0}, {1, 1, 1}, {2, 2, 2}, {0, 1, 2}, {2, 1, 0}};
        
        if((grid.size()) < 3 && (grid[0].size()) < 3)
            return 0;
        
        mcnt = 0;
        rowSize = grid.size();
        colSize = grid[0].size();
        for(i = 1;i < rowSize - 1;i++){
            for(j = 1;j < colSize - 1;j++){
                
                prev_sum = 0;
                m = i - 1;
                n = j - 1;
                
                //check sum
                for(x = 0;x < 3;x++){
                    prev_sum += grid[m + row[0][x]][n + col[0][x]];
                    
                    if(grid[m + row[0][x]][n + col[0][x]] >= 10){
                        prev_sum = -2147483648;
                    }
                }
                
                for(nth = 1;nth < 8;nth++){
                    sum = 0;
                    for(x = 0;x < 3;x++){
                        int num = grid[m + row[nth][x]][n + col[nth][x]];
                        sum += num;
                        if(num >= 10 || num <= 0){
                            prev_sum = -2147483648;
                        }
                    }
                    
                    if(prev_sum != sum)
                        break;
                }
                
                if(nth == 8) mcnt++;
            }
        }
        
        return mcnt;
    }
};