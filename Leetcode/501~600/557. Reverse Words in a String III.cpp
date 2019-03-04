class Solution {
public:
    void swap(char& a, char& b){
        char t = a; a = b; b = t;
    }
    
    void reverse(string& str, int start, int end){
        while(start < end)
            swap(str[start++], str[end--]);
    }
    
    string reverseWords(string s) {
        int index, size, start;
        
        start = 0;
        size = s.size();
        for(index = 0;index < size;index++)
            if(s[index] == ' ')
                reverse(s, start, index - 1), start = index + 1;
        reverse(s, start, size - 1);
        return s;
    }
};