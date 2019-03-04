
#define min(A, B) (A > B ? B : A)

long long int dp(long long int A){
    if(A <= 1) return 0;
    else if(A == 2) return 1;
    else if(A == 3) return 2;
    if((A & 0x01) == 0) return dp((A >> 1)) + 1;
    return min(dp(A - 1), dp(A + 1)) + 1;
}

int integerReplacement(int n) {
    return dp(n);
}