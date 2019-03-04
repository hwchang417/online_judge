int integerBreak(int n) {
    int mod = n % 3;
    int div = n / 3;
    if (n==2){return 1;}
    else if(n==3){return 2;}
    else if (mod == 0){return pow(3, div);}
    else if (mod == 1){return pow(3, (div-1))*4;}
    else return pow(3, div)*2;
    
}