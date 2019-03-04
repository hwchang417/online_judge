class Solution {
public:
    int sx, sy, ex, ey, empty = 0, res = 0, m, n;
    void dfs(vector<vector<int>> &grid, int x, int y){
        if(!check(grid, x, y)) return;
        if(x == ex && y == ey && empty == 0){
            res++;
            return;
        }
        
        grid[y][x] = -2;
        empty--;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
        grid[y][x] = 0;
        empty++;
    }
    
    bool check(vector<vector<int>> &grid, int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m && grid[y][x] >= 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int i, j;
        if(grid.size() == 0 || grid[0].size() == 0) return res;
        m = grid.size(); n = grid[0].size();
        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                if(grid[i][j] == 0){
                    empty++;
                }else if(grid[i][j] == 1){
                    sx = j; sy = i;
                }else if(grid[i][j] == 2){
                    ex = j; ey = i;
                }
            }
        }
        grid[sy][sx] = 0; empty++;
        dfs(grid, sx, sy);
        return res;
    }
};