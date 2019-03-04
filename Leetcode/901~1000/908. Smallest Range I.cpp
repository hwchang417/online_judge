class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int max, min;
        
        min = INT_MAX;
        max = INT_MIN;
        for(int n : A){
            if(max < n) max = n;
            if(min > n) min = n;
        }
        
        return (max - min) > (K << 1) ? max - min - (K << 1) : 0;
    }
};