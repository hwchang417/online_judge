class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int index, len, ch, cnt;
        int start, end;
        vector<int> element(2);
        vector<vector<int>> res;
        
        len = S.length();
        ch = S[0];
        cnt = 1;
        start = end = -1;
        for(index = 1;index < len;index++){
            if(ch == S[index]){
                start = (start == -1) ? index - 1 : start;
                cnt++;
            }else{
                ch = S[index];
                if(cnt >= 3){
                    end = index - 1;
                    element[0] = start;
                    element[1] = end;
                    res.push_back(element);
                }
                start = -1;
                cnt = 1;
            }
        }
        
        if(cnt >= 3){
            end = index - 1;
            element[0] = start;
            element[1] = end;
            res.push_back(element);
        }
        
        return res;
    }
};