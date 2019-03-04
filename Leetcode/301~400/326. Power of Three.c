#define TABLE_SIZE 20
bool isPowerOfThree(int n) {
    
    int table[TABLE_SIZE] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
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