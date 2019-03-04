class Solution {
public:
    void flip(vector<vector<int>>& A){
        int row, left, right;
        for(row = 0;row < A.size();row++){
            left = 0; right = A[0].size() - 1;
            while(left < right){
                int tmp = A[row][left];
                A[row][left] = A[row][right];
                A[row][right] = tmp;
                left++, right--;
            }
        }
    }
    
    void invert(vector<vector<int>>& A){
        int row, col;
        for(row = 0;row < A.size();row++)
            for(col = 0;col < A[0].size();col++)
                A[row][col] ^= 1;
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        flip(A);
        invert(A);
        return A;
    }
};