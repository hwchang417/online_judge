class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        int index, peak;
        int size = A.size();
        int num = A[0];
        
        index = 0;
        while(index < size - 1 && A[index] < A[index + 1]) index++;
        peak = index;
        while(index < size - 1 && A[index] > A[index + 1]) index++;
        
        return peak;
    }
};