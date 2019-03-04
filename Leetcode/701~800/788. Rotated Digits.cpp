class Solution {
public:
    int rotatedDigits(int N) {
        int n, t, r, ri, count, mod;
        int rotated[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        int multiply[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
        
        count = 0;
        for(n = 1;n <= N;n++){
            r = 0; t = n; ri = 0;
            while(ri < 10 && t != 0){
                mod = t % 10;
                if(rotated[mod] == -1) break;
                
                r = r + rotated[(t % 10)] * multiply[ri];
                t /= 10;
                
                ri++;
            }
            if(rotated[mod] != -1 && r > 0 && r != n) count++;
        }
        
        return count;
    }
};