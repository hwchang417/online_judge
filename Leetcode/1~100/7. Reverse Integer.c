int reverse(int x) {
    int i;
    int neg = 0;
    int x_rev = 0;
    int tmp_x_rev = x;
    int tmp_x;
    
    if(x < 0) neg = 1, x = - x;
    i = 0;
    while(i < 9 && (tmp_x = x / 10) != 0){
        x_rev = (x_rev << 3) + (x_rev << 1) + (x % 10);
        x = tmp_x;
        i++;
    }
    
    if(i == 9 && x % 10 != 0){
        long long int y = (long long int)x_rev;
        y = (y << 3) + (y << 1) + (long long int)(x % 10);
        x_rev = (x_rev << 3) + (x_rev << 1) + (x % 10);
        if(y != (long long int)x_rev){
            x_rev = 0;
        }
    }else{
        x_rev = (x_rev << 3) + (x_rev << 1) + (x % 10);
    }
    
    return neg == 1 ? - x_rev : x_rev;
}