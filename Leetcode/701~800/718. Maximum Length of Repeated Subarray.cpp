class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int indexA, indexB, max_len;
        int Asize = A.size(), Bsize = B.size();
        vector<vector<int>> suffix(Asize + 1, vector<int>(Bsize + 1, 0));
        
        max_len = 0;
        for(indexA = 1;indexA <= Asize;indexA++){
            for(indexB = 1;indexB <= Bsize;indexB++){
                if(A[indexA - 1] == B[indexB - 1]){
                    suffix[indexA][indexB] = suffix[indexA - 1][indexB - 1] + 1;
                    max_len = max(max_len, suffix[indexA][indexB]);
                }
            }
        }
        
        return max_len;
    }
};