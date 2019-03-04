class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool relation;
        int index, size;
        
        size = A.size();
        if(size == 0) return true;
        
        relation = A[0] < A[size - 1];
        for(index = 0;index < size - 1;index++){
            if(A[index] != A[index + 1] && relation != (A[index] < A[index + 1]))
                return false;
        }
        
        return true;
    }
};