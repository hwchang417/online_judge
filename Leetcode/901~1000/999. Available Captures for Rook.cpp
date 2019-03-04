
class Solution {
public:
    void rookPos(vector<vector<char>>& board, int *sx, int *sy){
        int row, col;
        for(row = 0;row < board.size();row++)
            for(col = 0;col < board[0].size();col++)
                if(board[row][col] == 'R'){
                    *sy = row, *sx = col;
                    return;
                }
    }
    
    int numRookCaptures(vector<vector<char>>& board) {
        int startx, starty, tmpx, tmpy, count = 0;
        
        rookPos(board, &startx, &starty);
        
        // check four directions
        tmpx = startx - 1;
        while(tmpx >= 0 && board[starty][tmpx] != 'p' && board[starty][tmpx] != 'B') tmpx--;
        if(tmpx >= 0) count += board[starty][tmpx] == 'p';
        
        tmpy = starty - 1;
        while(tmpy >= 0 && board[tmpy][startx] != 'p' && board[tmpy][startx] != 'B') tmpy--;
        if(tmpy >= 0) count += board[tmpy][startx] == 'p';
        
        tmpx = startx + 1;
        while(tmpx < board[0].size() && board[starty][tmpx] != 'p' && board[starty][tmpx] != 'B') tmpx++;
        if(tmpx < board[0].size()) count += board[starty][tmpx] == 'p';
        
        tmpy = starty + 1;
        while(tmpy < board.size() && board[tmpy][startx] != 'p' && board[tmpy][startx] != 'B') tmpy++;
        if(tmpy < board.size()) count += board[tmpy][startx] == 'p';
        
        return count;
    }
};