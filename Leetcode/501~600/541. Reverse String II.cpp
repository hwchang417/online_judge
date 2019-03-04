class Solution {
public:
    
    void reverse(string& s, int from, int to){
        while(from < to){
            swap(s[from], s[to]);
            from++;
            to--;
        }
    }
    
    inline void swap(char &ch1, char &ch2){
        char tmp = ch1;
        ch1 = ch2;
        ch2 = tmp;
    }
    
    string reverseStr(string s, int k) {
        int index, size, k2;
        
        size = s.size() - 1;
        k2 = k << 1;
        for(index = 0;index + k <= size;index += k2)
            reverse(s, index, index + k - 1);
        reverse(s, index, size);
        
        return s;
    }
};