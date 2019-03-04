class Solution {
public:
    
    void dfs(string& s, vector<string>& v, vector<vector<string>>& res, int from){
        bool b;
        int l, r, to;
        if(from >= s.size()){
            res.push_back(v);
            return;
        }
        
        for(to = from;to < s.size();to++){
            b = true;
            l = from; r = to;
            //check string is palindrome?
            while(b && l < r) if(s[l++] != s[r--]) b = false;
            if(b){
                //substr(index, length)
                v.push_back(s.substr(from, to - from + 1));
                dfs(s, v, res, to + 1);
                v.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        dfs(s, v, res, 0);
        return res;
    }
};