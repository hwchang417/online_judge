#define isDot(s, idx) (s[idx] == '.')
#define isSign(s, idx) (s[idx] == '+' || s[idx] == '-')
#define isDigit(s, idx) (s[idx] >= '0' && s[idx] <= '9') 
#define isExp(s, idx) (s[idx] == 'e')
#define skipDigits(s, idx) while(idx < size && isDigit(s, idx)) idx++;
#define skipWhiteSpace(s, idx) for(;idx < size && s[idx] == ' ';idx++)

class Solution {
public:
    
    bool isNumber(string s) {
        int idx, size, prev_idx;
        
        idx = 0; size = s.size();
        
        //skipping whitespace
        skipWhiteSpace(s, idx);
        
        //all of characters are whitespace
        if(idx == size) return false;
        
        //e.g. +1.2
        if(isSign(s, idx)) idx++;
        
        if(isDigit(s, idx)){
            //1.2
            idx++;
            skipDigits(s, idx);
            if(isDot(s, idx)) idx++;
            skipDigits(s, idx);
        }else if(isDot(s, idx)){
            //.123
            idx++;
            prev_idx = idx;
            skipDigits(s, idx);
            //no digits exist
            if(prev_idx == idx) return false;
        }else return false; //e9

        if(isExp(s, idx)){
            //1e+1.2
            idx++;
            if(isSign(s, idx)) idx++;
            
            prev_idx = idx;
            skipDigits(s, idx);
            //no digits exist
            if(prev_idx == idx) return false;
        }
        
        //skipping whitespace
        skipWhiteSpace(s, idx);
        
        return idx == size;
    }
};