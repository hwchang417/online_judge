class Solution {
public:
    bool isEqual(char* table, string& word, string& pattern){
        int cptr, index;
        int size = word.size();
        
        //pattern to word
        memset(table, -1, sizeof(char) * 27);
        for(cptr = 0;cptr < size;cptr++){
            index = pattern[cptr] - 'a';
            if(table[index] == -1)
                table[index] = word[cptr];
            else if(table[index] != word[cptr])
                return false;
        }
        
        //word to pattern
        memset(table, -1, sizeof(char) * 27);
        for(cptr = 0;cptr < size;cptr++){
            index = word[cptr] - 'a';
            if(table[index] == -1)
                table[index] = pattern[cptr];
            else if(table[index] != pattern[cptr])
                return false;
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int index, size;
        char table[27];
        vector<string> res;
        
        size = words.size();
        for(index = 0;index < size;index++)
            if(isEqual(table, words[index], pattern)) 
                res.push_back(words[index]);
        
        return res;
    }
};