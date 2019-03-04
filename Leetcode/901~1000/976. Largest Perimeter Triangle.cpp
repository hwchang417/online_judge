class Solution {
public:
    bool isTriangle(int a, int b, int c){
        return a + b > c && a + c > b && b + c > a;
    }
    
    int largestPerimeter(vector<int>& A) {
        int i, j, k, size, sum;
        sort(A.begin(), A.end());
        
        sum = 0; size = A.size();
        for(i = size - 1;i > 1;i--){
            sum += A[i];
            for(j = i - 1;j > 0;j--){
                sum += A[j];
                for(k = j - 1;k >= 0;k--)
                    if(isTriangle(A[i], A[j], A[k])){
                        return sum + A[k];
                    }else break;
                sum -= A[j];
            }
            sum -= A[i];
        }
        return 0;
    }
};