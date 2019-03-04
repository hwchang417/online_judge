// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int g;
        long long int mid, left, right;
        
        left = 0; g = right = n;
        while(g){
            mid = (long long int)(left + right) >> 1;
            g = guess(mid);
            
            if(g == 1)
                left = mid + 1;
            else if(g == -1)
                right = mid - 1;
        }
        
        return mid;
    }
};