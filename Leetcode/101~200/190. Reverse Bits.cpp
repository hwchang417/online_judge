class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i;
        int size = sizeof(n) * 8;
        uint32_t reverse = 0;
        
        for(i = 0;i < size;i++){
            reverse <<= 1;
            reverse |= (n & 0x01);
            n >>= 1;
        }
        return reverse;
    }
};