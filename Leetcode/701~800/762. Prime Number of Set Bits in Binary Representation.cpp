class Solution {
public:
    int countOneBits(int n){
        int count = 0;
        while(n)
            count += (n & 0x01), n >>= 1;
        return count;
    }
    
    int countPrimeSetBits(int L, int R) {
        int num, count = 0;
        bool pTable[21] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};
        
        for(num = L;num <= R;num++)
            count += pTable[countOneBits(num)];
        
        return count;
    }
};