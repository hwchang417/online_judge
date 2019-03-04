class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int i, cnt, max, size = A.size();
        if(size <= 1) return size;
        int cmp, prev_cmp = INT_MAX;
        cnt = max = 0;
        for(i = 1;i < size;i++){
            if(A[i - 1] == A[i]){ cnt = 0; prev_cmp = INT_MAX; continue;}
            cmp = A[i - 1] > A[i];
            if(prev_cmp != cmp){
                cnt++;
                if(cnt > max) max = cnt;
            }else cnt = 1;
            prev_cmp = cmp;
        }
        return max + 1;
    }
};