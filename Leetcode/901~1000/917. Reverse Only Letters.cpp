class Solution {
public:
    bool isLetter(char c){
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }
    
    string reverseOnlyLetters(string S) {
        int r, l, size;
        string res(S);
        
        size = S.size();
        l = 0;
        r = size - 1;
        while(1){
            while(l < size && !isLetter(res[l])) l++;
            while(r >= 0 && !isLetter(res[r])) r--;
            
            if(l >= r) break;
            
            char tmp = res[l];
            res[l++] = res[r];
            res[r--] = tmp;
        }
        
        return res;
    }
};