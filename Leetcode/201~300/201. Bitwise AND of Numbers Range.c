int rangeBitwiseAnd(int m, int n) {
    int sum, index;
    
    //sum = 0xFFFFFFFF;
    //for(index = m;index < n && sum != 0;index++)
    //    sum &= index;
    //sum &= n;
    //return sum;
    
    //n & n - 1
    //1100 & 1011 = 1000, 12 & 11 省去 12 ~ 9 的計算
    while(n > m)
        n &= n - 1;
    return n;
    
    //52~56, only reserve the left two bit
    //110100
    //110101
    //110110
    //110111
    //111000
    index = 0;
    while(n != m){
        n >>= 1;
        m >>= 1;
        index++;
    }
    return n << index;
}