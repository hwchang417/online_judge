class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>::iterator iter;
        map<string, vector<string>> m;
        vector<vector<string>> res;
        
        for(string str : strs){
            string key = rearrange(str);
            m[key].push_back(str);
        }
        
        for(iter = m.begin();iter != m.end();iter++){
            res.push_back(iter->second);
        }
        
        return res;
    }
    
    string rearrange(string key){
        string res;
        int hash[26] = {0};
        for(char c : key) hash[c - 'a']++;
        for(int idx = 0;idx < 26;idx++) 
            while(hash[idx]--) 
                res += (idx + 'a');
        return res;
    }
    
};