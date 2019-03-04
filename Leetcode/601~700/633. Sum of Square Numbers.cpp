class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i, j, sum, si, sj;
        for(i = 0;(si = i * i) <= c;i++){
            sum = c - si;
            j = sqrt(sum);
            if(sum == j * j) return true;
        }
        return false;
    }
};