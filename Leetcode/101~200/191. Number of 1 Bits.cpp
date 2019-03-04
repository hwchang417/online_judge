class Solution {
public:    
    //n &= (n-1) 等同於刪除最右邊為1的bit
    int hammingWeight(uint32_t n) {
        int count, tmp;
        count = 0;
        while(n){
            n &= (n - 1);
            count++;
        }
        return count;
    }
    
    int hammingWeight2(uint32_t n) {
        int count, i;
        int size = sizeof(n) << 3;
        count = 0;
        for(i = 0;i < size;i++){
            count += (n & 0x01);
            n >>= 1;
        }
        return count;
    }
};