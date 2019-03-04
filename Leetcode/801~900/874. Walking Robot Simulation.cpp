

enum COMMAND{
    TURN_LEFT = -2,
    TURN_RIGHT = -1
};

enum DIRECTION{
    NORTH = 0,
    WEST,
    SOUTH,
    EAST
};

class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x, y;
        int item, max;
        int dir;
        int comSize = commands.size();
        int obSize = obstacles.size();
        map<int, vector<int>> hash;
        map<int, vector<int>>::iterator iter;
        int index;
        
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};
        
        for(index = 0;index < obSize;index++)
            hash[obstacles[index][0]].push_back(obstacles[index][1]);
        
        max = x = y = 0;
        dir = NORTH;
        for(int nth = 0;nth < comSize;nth++){
            if(commands[nth] >= 1){
                //forward
                for(int step = 1;step <= commands[nth];step++){
                    int dX = x + dx[dir];
                    int dY = y + dy[dir];
                    
                    if((iter = hash.find(dX)) == hash.end()){
                        x += dx[dir];
                        y += dy[dir];
                    }else{
                        
                        vector<int>& tmp = iter->second;
                        int tsize = tmp.size();
                        for(item = 0;item < tsize;item++){
                            if(dY == tmp[item]){
                                step = 10;
                                break;
                            }
                        }
                        if(item == tsize){
                            x += dx[dir];
                            y += dy[dir];
                        }
                    }

                }
                
                int distance = x * x + y * y;
                if(max < distance)
                    max = distance;
                
            }else{
                switch(commands[nth]){
                    case TURN_LEFT: dir = (dir + 1) % 4; break;
                    case TURN_RIGHT: dir = (dir - 1) == -1 ? EAST : dir - 1; break;
                    default: break;
                }
            }
        }
        
        return max; 
    }
};