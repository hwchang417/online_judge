#define getDistance(p1, p2) (abs(p1.first - p2.first) + abs(p1.second - p2.second))

class Solution {
public:
    void dfs(vector<vector<int>>& A, int row, int col, int nr, int nc, int group){
        if(A[row][col] != 1) return ;
            
        A[row][col] = group; 
        
        if(row > 0 && A[row - 1][col] == 1)
            dfs(A, row - 1, col, nr, nc, group);
        
        if(col > 0 && A[row][col - 1] == 1)
            dfs(A, row, col - 1, nr, nc, group);
        
        if(row < nr - 1 && A[row + 1][col] == 1)
            dfs(A, row + 1, col, nr, nc, group);
        
        if(col < nc - 1 && A[row][col + 1] == 1)
            dfs(A, row, col + 1, nr, nc, group);
        
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int row, col, group, rowSize, colSize, minDistance;
        vector<pair<int, int>> groups[4];
        
        //4 connected labeling
        group = 2;
        rowSize = A.size();
        colSize = A[0].size();
        for(row = 0;row < rowSize;row++){
            for(col = 0;col < colSize;col++){
                if(A[row][col] == 1){
                    dfs(A, row, col, rowSize, colSize, group);
                    group++;
                }
            }
        }
        
        //labeling之後把對應的group加到對應的group

        for(row = 0;row < rowSize;row++)
            for(col = 0;col < colSize;col++)
                groups[A[row][col]].push_back(pair<int, int>(row, col));
        
        minDistance = INT_MAX;
        //兩個group做O(N^2)的棋盤式檢查
        for(pair<int, int> p1 : groups[2]){
            for(pair<int, int> p2 : groups[3]){
                minDistance = min(minDistance, getDistance(p1, p2));
            }
        }
        
        
        return minDistance - 1;
    }
};