class Solution {
public:

    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int i, j, k;
        int direction;
        vector<int> res;
        vector<int> step(2);
        int nr = matrix.size(); if(nr == 0) return res;
        int nc = matrix[0].size(); if(nc == 0) return res;
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        step[0] = nc;
        step[1] = nr - 1;
        direction = i = 0;
        j = -1;
        while(step[direction & 0x01]){
            for(k = 0;k < step[direction & 0x01];k++){
                i += dirs[direction][0]; j += dirs[direction][1];
                res.push_back(matrix[i][j]);
            }
            step[direction & 0x01]--;
            direction = (direction + 1) % 4;
        }

        return res;
    }

};