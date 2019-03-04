class Solution {
public:
    vector<string> split2part(const std::string& s, char delimiter)
    {
        int index;
        vector<string> tokens;
        string token;
        
        for(index = 0;index < s.size();index++)
            if(s[index] == ' ') break;
        
        tokens.push_back(s.substr(0, index));
        tokens.push_back(s.substr(index + 1, s.size() - index - 1));
        
        return tokens;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, digits, letters;
        vector<pair<string, string>> m;
        
        for(string str : logs){
            vector<string> splited = split2part(str, ' ');
            if(splited[1][0] >= '0' && splited[1][0] <= '9') 
                digits.push_back(str);
            else
                m.push_back({splited[0], splited[1]});
        }
        
        sort(m.begin(), m.end(), 
             [](const pair<string, string>& lhs, const pair<string, string>& rhs) {return lhs.second < rhs.second;}
        );
        
        for(pair<string, string> p : m)
            res.push_back(p.first + " " + p.second);
        
        for(string str : digits)
            res.push_back(str);
        
        return res;
    }
};