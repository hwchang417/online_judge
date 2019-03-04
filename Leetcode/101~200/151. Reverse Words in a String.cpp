class Solution {
public:
    
    void reverseWord(string &s, int start, int end){
        
        for(;start < end;start++, end--){
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
        }
    }
    
    void trimSpaces(string &s){
        int start, end, size;
        size = s.size();
        start = 0;
        end = size - 1; 
        
        if(s[end] == ' '){
            while(s[end] == ' ' && end >= 0)
                end--;
            
            if(end == -1){
                s = "";
                return;
            }else{
                s.erase(end + 1, size - 1 - end);
            }
        }
        
        size = s.size();
        if(s[start] == ' '){
            while(s[start] == ' ' && start < size) start++;
            s.erase(0, start);
        }
        
    }
    
    void trimTwoSpaces(string &s){
        int start, end, size, index, isTwoSpace;
        size = s.size();
        isTwoSpace = 0;
        
        for(index = size - 1;index >= 0;index--){
            if(s[index] == ' '){
                if(isTwoSpace == 0) end = index;
                else start = index;
                isTwoSpace++;
            }else{
                if(isTwoSpace >= 2)
                    s.erase(start, end - start);
                isTwoSpace = 0;
            }
        }
        
    }
    
    void reverseWords(string &s) {
        int index, start, end, size;
        
        reverse(s.begin(), s.end());
        
        trimSpaces(s);
        trimTwoSpaces(s);
        
        start = 0;
        size = s.size();
        end = size - 1;
        for(index = 0;index < size;index++){
            if(s[index] == ' '){
                end = index - 1;
                reverseWord(s, start, end);
                start = index + 1;
            }
        }
        
        if(end < start || end == size - 1){
            reverseWord(s, start, size - 1);
        }
        
    }
};