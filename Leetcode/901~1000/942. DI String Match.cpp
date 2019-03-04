class Solution {
public:
    vector<int> diStringMatch(string S) {
        int idx, d = S.size(), i = 0;
        vector<int> res;
        
        for(char c : S){
            if(c == 'I')
                res.push_back(i++);
            else
                res.push_back(d--);
        }
        res.push_back(i);
        return res;
    }
};