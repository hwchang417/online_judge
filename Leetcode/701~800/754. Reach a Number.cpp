class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long int res, sum, n = ceil((-1 + sqrt(1.0 + 8.0 * target)) / 2);
        sum = ((n + 1) * n) >> 1;
        if(target == sum) return n;
        res = sum - target;
        if((res & 1) == 0) return n;
        return n + (n & 1 ? 2 : 1);
    }
};