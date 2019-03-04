class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int rowSize, colSize;
        int row, col;
        
        rowSize = rooms.size();
        queue<int> next;
        vector<int> visit(rowSize, 0);
        
        next.push(0);
        //push all room key to queue
        while(!next.empty()){
            int r = next.front();
            next.pop();
            if(!visit[r]){
                visit[r] = 1;
                colSize = rooms[r].size();
                for(col = 0;col < colSize;col++){
                    next.push(rooms[r][col]);
                }
            }
        }
        
        for(row = 0;row < rowSize && visit[row];row++);
        
        return row == rowSize;
    }
};