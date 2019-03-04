class Solution {
public:
    int findComplement(int num) {
        int tmp, bits;
        
        bits = 0;
        tmp = num;
        while(num){
            bits++;
            num >>= 1;
        }
        
        return (0xFFFFFFFF << bits) ^ (~tmp);
    }
};