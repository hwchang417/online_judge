#define abs(num) (num < 0 ? - num : num)

int divide(int dividend, int divisor) {
    long long int neg;
    
    neg = (dividend < 0) ^ (divisor < 0);
    
    long long int dend = abs((long long int)dividend);
    long long int dsor = abs((long long int)divisor);
    
    dend = dend / dsor;
    if(!neg && dend > INT_MAX) return INT_MAX; 
    return neg ? -dend : dend;
}