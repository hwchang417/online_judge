class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int idx, ret;
        map<int, bool> m;
        
        for(idx = 0;idx < A.size();idx++){
            if(m.find(A[idx]) != m.end())
                return A[idx];
            m[A[idx]] = true;
        }
        
        return -1;
    }
};