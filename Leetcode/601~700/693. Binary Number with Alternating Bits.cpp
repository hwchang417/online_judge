class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit;
        
        bit = n & 0x01; n >>= 1;
        while(n > 0){
            int tmp = n & 0x01;
            if(!(bit ^ (tmp))) return false;
            bit = tmp;
            n >>= 1;
        }
        return true;
    }
};