class Solution {
public:
    int titleToNumber(string s) {
        int result;
        int index;
        int size = s.size();
        
        result = 0;
        for(index = 0;index < size;index++){
            //version 1, 編譯後會多一個 mov
            // result *= 26;
            // result += (s[index] - 'A' + 1);
            //version 2
            result = result * 26 + (s[index] - 'A' + 1);
        }
        
        return result;
    }
};