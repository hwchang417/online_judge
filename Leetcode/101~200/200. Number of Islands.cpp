
#define min(a, b) (a > b ? b : a)

typedef struct coord Coord;
struct coord{
    int X, Y;
    coord(int y, int x) : X(x), Y(y){}
};

class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        //BFS
        int lcnt;
        int row, col, rowSize, colSize;
        queue<Coord> q;
        
        rowSize = grid.size();
        if(rowSize == 0) return 0;
        
        colSize = grid[0].size();
        if(colSize == 0) return 0;
        
        lcnt = 0;
        for(row = 0;row < rowSize;row++){
            for(col = 0;col < colSize;col++){
                if(grid[row][col] == '1'){
                    lcnt++;
                    grid[row][col] = '2';
                    q.push(Coord(row, col));
                    while(!q.empty()){
                        Coord c = q.front();
                        grid[c.Y][c.X] = '2';
                        q.pop();
                        
                        if(c.X > 0 && grid[c.Y][c.X - 1] == '1')
                            grid[c.Y][c.X - 1] = '2', q.push(Coord(c.Y, c.X - 1));
                        
                        if(c.Y > 0 && grid[c.Y - 1][c.X] == '1')
                            grid[c.Y - 1][c.X] = '2', q.push(Coord(c.Y - 1, c.X));
                        
                        if(c.X < colSize - 1 && grid[c.Y][c.X + 1] == '1')
                            grid[c.Y][c.X + 1] = '2', q.push(Coord(c.Y, c.X + 1));
                        
                        if(c.Y < rowSize - 1 && grid[c.Y + 1][c.X] == '1')
                            grid[c.Y + 1][c.X] = '2', q.push(Coord(c.Y + 1, c.X));
                    }
                }
            }
        }
        return lcnt;
    }
};