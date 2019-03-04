class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //reset to all 1
        vector<int> res(rowIndex + 1, 1);
        int range, last;
        
        for(last = 2;last <= rowIndex;last++)
            for(range = last - 1;range >= 1;range--)
                res[range] = res[range] + res[range - 1];
        
        return res;
    }
};