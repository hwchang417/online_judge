class Solution {
public:
    
    bool isSorted(vector<string>& A){
        int row;
        for(row = 1;row < A.size();row++){
            if(A[row - 1] > A[row]){
                return false;
            }
        }
        return true;
    }
    
    int minDeletionSize(vector<string>& A) {
        int row, col, len, size, delSize;
        
        delSize = 0;
        len = A[0].size();
        size = A.size();
        for(col = 0;col < len;){
            if(isSorted(A)) break;
            
            for(row = 1;row < size;row++){
                if(A[row - 1] > A[row] && A[row - 1][col] > A[row][col]){
                    delSize++;
                    break;
                }
            }
            
            if(row != size){
                for(row = 0;row < size;row++){
                    A[row].erase(col, 1);
                }
            }else col++;
        }
        
        return delSize;
    }
};