class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int idx, c, size, cnt;
        if(A.empty()) return 0;
        
        cnt = 0;
        size = A.size();
        for(c = 0;c < A[0].size();c++){
            for(idx = 1;idx < size;idx++){
                if(A[idx][c] < A[idx - 1][c]){
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};