class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0, times;
        // while(n > 0){
        //     n /= 5;
        //     res += n;
        // }
        while(n > 0){
            times = n / 5;
            res += times;
            n = times;
        }
        return res;
    }
};