class Solution {
public:
    bool checkRecord(string s) {
        int a, l;
        
        a = l = 0;
        for(char c : s){
            if(c == 'A')
                if(++a >= 2) return false;
            if(c == 'L'){
                if(++l >= 3) return false;
            }
            else l = 0;
        }
        return true;
    }
};