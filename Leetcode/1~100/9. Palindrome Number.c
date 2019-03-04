bool isPalindrome(int x) {
    if(x < 0) return false;
    
    //reverse integer
    int x_10;
    int x_rev = 0;
    int i = 0;
    int tmp_x = x;
    long long int tmp_x_rev;
    bool result;
    
    while(i < 9 && (x_10 = x / 10) != 0){
        x_rev = ((x_rev << 3) + (x_rev << 1)) + x % 10;
        x = x_10;
        i++;
    }
    
    if(i == 9 && (x_10 = x / 10) != 0){
        tmp_x_rev = ((long long int)(x_rev << 3) + (long long int)(x_rev << 1)) + x % 10;
        result = tmp_x_rev <= 2147483647 ? (int)tmp_x_rev == tmp_x : false;
    }else{
        x_rev = ((x_rev << 3) + (x_rev << 1)) + x % 10;
        result = x_rev == tmp_x;
    }
    
    
    return result;
}