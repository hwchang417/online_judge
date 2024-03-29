class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        
        while((num & 0x01) == 0)           num >>= 1;
        while(num % 3 == 0)           num /= 3;
        while(num % 5 == 0)           num /= 5;
        
        return num == 1;
    }
};