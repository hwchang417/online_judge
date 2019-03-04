class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int cnt, dir, numOfElements, step, numOfSteps;
        int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        numOfElements = R * C;
        vector<vector<int>> res(numOfElements);
        
        dir = cnt = step = 0;
        numOfSteps = 1;
        while(cnt < numOfElements){
            if(r0 >= 0 && r0 < R && c0 >= 0 && c0 < C)
                res[cnt++] = {r0, c0};
            c0 += offset[dir][0];
            r0 += offset[dir][1];
            
            if(step == numOfSteps - 1){
                if(dir & 0x01) numOfSteps++;
                dir = (dir == 3) ? 0 : dir + 1;
                step = 0;
            }else step++;
        }
        
        return res;
    }
};