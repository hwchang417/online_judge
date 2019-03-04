bool reorderedPowerOf2(int N) {
    //1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288
    //1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824
    //2147483648
    char ctable[33] = {0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10};
    char table[33][10] = {  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
                            {0, 1, 0, 0, 0, 0, 1, 0, 0, 0}, 
                            {0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, 
                            {0, 1, 1, 0, 0, 0, 0, 0, 1, 0}, 
                            {0, 0, 1, 0, 0, 1, 1, 0, 0, 0}, 
                            {0, 1, 1, 0, 0, 1, 0, 0, 0, 0}, 
                            {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, 
                            {1, 0, 1, 0, 1, 0, 0, 0, 1, 0}, 
                            {1, 0, 0, 0, 1, 0, 1, 0, 0, 1}, 
                            {0, 1, 1, 0, 0, 0, 0, 0, 1, 1}, 
                            {0, 1, 0, 1, 1, 0, 1, 0, 1, 0}, 
                            {0, 0, 1, 1, 0, 0, 1, 1, 1, 0}, 
                            {0, 0, 0, 1, 0, 2, 2, 0, 0, 0}, 
                            {1, 2, 1, 1, 0, 0, 0, 1, 0, 0}, 
                            {0, 1, 2, 0, 2, 0, 1, 0, 0, 0}, 
                            {0, 0, 2, 0, 1, 1, 0, 0, 2, 0}, 
                            {1, 1, 0, 0, 1, 1, 1, 1, 1, 0}, 
                            {1, 1, 2, 0, 0, 1, 0, 1, 0, 1}, 
                            {1, 1, 0, 1, 3, 0, 0, 0, 0, 1}, 
                            {1, 0, 0, 1, 0, 0, 1, 0, 4, 0}, 
                            {0, 2, 1, 0, 0, 0, 2, 3, 0, 0}, 
                            {0, 0, 1, 3, 2, 2, 0, 0, 0, 0}, 
                            {1, 1, 0, 0, 1, 0, 2, 1, 2, 0}, 
                            {0, 2, 2, 1, 1, 0, 0, 2, 1, 0}, 
                            {0, 0, 1, 1, 2, 2, 2, 0, 1, 0}, 
                            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1}, 
                            {1, 2, 1, 1, 2, 0, 0, 2, 1, 0}
                          };
    char tableN[10] = {0};
    int count, powerOf2, tIndex, nIndex;
    count = 0;
    
    while(N != 0) tableN[N % 10]++, N /= 10, count++;
    
    for(tIndex = 1;tIndex <= 32 && ctable[tIndex] <= count;tIndex++)
        if(ctable[tIndex] == count){
            for(nIndex = 0;nIndex < 10;nIndex++)
                if(tableN[nIndex] != table[tIndex][nIndex]) break;
            if(nIndex == 10) return true; 
        }
    
    return false;
}