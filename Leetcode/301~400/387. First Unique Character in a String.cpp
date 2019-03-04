class Solution {
public:
    int firstUniqChar(string s) {
        int index, size;
        int table[27] = {0};
        
        size = s.size();
        for(index = 0;index < size;index++)
            table[s[index] - 'a']++;
        
        for(index = 0;index < size;index++)
            if(table[s[index] - 'a'] == 1)
                return index;
        
        return -1;
    }
};