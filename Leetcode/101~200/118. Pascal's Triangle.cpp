class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> vec;
        int row, col;
        
        if(numRows == 0) return res;
        
        vec.push_back(1);
        res.push_back(vec);
        for(row = 1;row < numRows;row++){
            vec.clear();
            vec.push_back(1);
            for(col = 1;col < row;col++)
                vec.push_back(res[row - 1][col] + res[row - 1][col - 1]);
            vec.push_back(1);
            res.push_back(vec);
        }
        return res;
    
    }
};