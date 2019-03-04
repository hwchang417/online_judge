class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> s;
        int len = A.size(), cnt;
        
        cnt = 0;
        for(int i = 0;i < len;i++){
            cnt |= A[i];
            s.insert(cnt);
        }

        for(int i = 1; i < len;i++){
            if((A[i] & A[i - 1]) != A[i - 1]){
                cnt = 0;
                for(int j = i;j < len && cnt != 0x7FFFFFFF;j++){
                    cnt |= A[j];
                    s.insert(cnt);
                    if((cnt & A[i - 1]) == A[i - 1])
                        break;
                }
            }
        }
        return s.size();
    }
};