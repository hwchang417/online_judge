class Solution {
public:
    std::vector<std::string> split(const std::string& s, char delimiter)
    {
       std::vector<std::string> tokens;
       std::string token;
       std::istringstream tokenStream(s);
       while (std::getline(tokenStream, token, delimiter))
       {
          tokens.push_back(token);
       }
       return tokens;
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int>::iterator iter;
        map<string, int> set;
        vector<string> res; 
        int index, lenA, lenB;
        vector<string> asplit = split(A, ' ');
        vector<string> bsplit = split(B, ' ');
        
        lenA = asplit.size(); 
        for(index = 0;index < lenA;index++){
            
            if(set.find(asplit[index]) == set.end())
                set[asplit[index]] = 1;
            else
                set[asplit[index]] = 2;
        }
        lenB = bsplit.size();
        for(index = 0;index < lenB;index++){
            if(set.find(bsplit[index]) == set.end())
                set[bsplit[index]] = 1;
            else
                set[bsplit[index]] = 2;
        }
        
        for(iter = set.begin();iter != set.end();iter++)
            if(iter->second == 1)
                res.push_back(iter->first);
        
        return res;
    }
};