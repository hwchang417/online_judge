class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int index, max, min;
        vector<int> maximum(A.size()), minimum(A.size());
        
        max = INT_MIN;
        min = INT_MAX;
        for(index = 0;index < A.size();index++){
            if(max < A[index]) max = A[index];
            maximum[index] = max;
        }
        
        for(index = A.size() - 1;index >= 0;index--){
            minimum[index] = min;
            if(min > A[index]) min = A[index];
        }
    
        for(index = 0;index < A.size();index++)
            if(minimum[index] >= maximum[index]) return index + 1;
        
        return -1;
    }
};