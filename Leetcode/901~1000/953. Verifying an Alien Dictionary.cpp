class Solution {
public:
    char order_map[27] = {0};
    
    //return true if str1 <= str2
    bool isGreater(string& str1, string& str2){
        int idx, size = min(str1.size(), str2.size());
        
        for(idx = 0;idx < size && order_map[str1[idx] - 'a'] == order_map[str2[idx] - 'a'];idx++);
        
        return idx == size ? str1.size() <= str2.size() : order_map[str1[idx] - 'a'] < order_map[str2[idx] - 'a'];
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        int idx = 0;
        //make order map
        for(char c : order) order_map[c - 'a'] = idx++;
        
        for(idx = 1;idx < words.size() && isGreater(words[idx - 1], words[idx]);idx++);
       
        return idx == words.size();
    }
};