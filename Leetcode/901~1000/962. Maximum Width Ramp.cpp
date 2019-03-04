class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int idx, ret = 0;
        stack<int> s;
        
        s.push(0);
        for(idx = 1;idx < A.size();idx++)
            while(A[s.top()] > A[idx])
                s.push(idx);
        
        for(idx = A.size() - 1;idx >= 0;idx--)
            while(!s.empty() && A[s.top()] <= A[idx])
                ret = max(ret, idx - s.top()), s.pop();
        
        return ret;
    }
};