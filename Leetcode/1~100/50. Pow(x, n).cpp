class Solution {
public:
    double myPow(double x, int n)
    {
        double result = 1;
         
        if (n == -2147483648)
        {
            n = n + 2;
        }
         
        int tempN = n > 0 ? n : -n;
         
        for (int i = 31; i >= 0; i--)
        {
            result = result * result;
            if ((tempN & (1 << i)) > 0)  result = result * x;
        }
         
        if (n < 0) result = 1/result;
         
        return result;
    }


};