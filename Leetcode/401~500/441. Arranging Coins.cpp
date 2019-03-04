class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + (int)sqrt(1 + ((long long)n << 3))) >> 1;
    }
};