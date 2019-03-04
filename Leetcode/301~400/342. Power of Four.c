#define TABLE_SIZE 16
bool isPowerOfFour(int n) {
    
    int table[TABLE_SIZE] = {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
    int start, end, mid;
    
    start = 0; end = TABLE_SIZE - 1;
    while(start <= end){
        mid = (start + end) >> 1;
        if(table[mid] == n) return true;
        
        if(table[mid] < n) start = mid + 1;
        else end = mid - 1;
    }
    
    return false;
}