class Solution {
public:
    bool isPunctuaion(char in){
        return in == '\0' || in == ' ' || in == '!' || in == '?' || in == '\'' || in == ',' || in == ';' || in == '.';
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int max, psize;
        string splited_word, max_freq_word;
        map<string, bool> banned_map;
        map<string, int> para_map;
        
        max = 0;
        for(string word : banned)
            banned_map[word] = true;
        
        psize = paragraph.size() + 1;
        for(int index = 0;index < psize;index++){
            if(isPunctuaion(paragraph[index])){
                if(splited_word.size() == 0) continue;
                std::transform(splited_word.begin(), splited_word.end(), splited_word.begin(), ::tolower);
                
                if(banned_map.find(splited_word) == banned_map.end()){
                    if(para_map.find(splited_word) != para_map.end()){
                        para_map[splited_word]++;
                    }else{
                        para_map[splited_word] = 1;
                    }
                
                    if(max < para_map[splited_word]){
                        max_freq_word = splited_word;
                        max = para_map[splited_word];
                    }
                }
                splited_word = "";
            }else
                splited_word += paragraph[index];
        }
        
        return max_freq_word;
    }
};