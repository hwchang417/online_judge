class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i, j, maxCount;
        
        maxCount = -1;
        for(i = 0, j = 0;i < A.size();i++){
            K -= (A[i] == 0);
            while(K < 0) K += (A[j++] == 0);
            if((i - j) + 1 > maxCount)
                maxCount = (i - j) + 1;
        }
        
        return maxCount;
    }
};