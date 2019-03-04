class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int idx, half;
        map<int, int> m;
        sort(A.begin(), A.end());
        
        for(int n : A){
            if(m.find(n) != m.end()) m[n]++;
            else m[n] = 1;
        }
        
        for(idx = A.size() - 1;idx >= 0;idx--){
            if(m.find(A[idx]) == m.end() || m[A[idx]] == 0) continue;
            if(A[idx] > 0){
                if(A[idx] & 0x01) return false;
                half = A[idx] >> 1;
            }else{
                half = A[idx] * 2;
            }
            if(m.find(half) != m.end() && m[half] > 0) m[half]--;
            else return false;
            m[A[idx]]--;
        }
        
        return true;
    }
};