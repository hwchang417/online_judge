class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int sum = 0, next = 0;
        sort(A.begin(), A.end());
        for(int n : A){
            sum += max(next - n, 0);
            next = max(next, n) + 1;
        }
        return sum;
    }
};
