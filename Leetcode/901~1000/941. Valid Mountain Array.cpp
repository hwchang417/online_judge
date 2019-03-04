class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int idx, size;
        
        idx = 0; size = A.size() - 1;
        while(idx < size){
            if(A[idx] >= A[idx + 1]) break;
            idx++;
        }
        
        if(idx == 0 || idx == size) return false;
        
        while(idx < size){
            if(A[idx] <= A[idx + 1]) break;
            idx++;
        }
        
        return idx == size;
    }
};