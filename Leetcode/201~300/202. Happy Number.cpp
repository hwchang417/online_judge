class Solution {
public:
    bool isHappy(int n) {
        int sum, square;
        map<int, bool> res;
        
        while(n != 1){
            sum = 0;
            while(n != 0) square = n % 10, sum += (square * square), n /= 10;
            
            if(res.find(sum) != res.end()) return false;
            
            res[sum] = true;
            n = sum;
        }
        
        return true;
    }
};