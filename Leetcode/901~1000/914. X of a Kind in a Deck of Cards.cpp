class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int res, min = INT_MAX, min_index = 0;
        map<int, int> m;
        for(int n : deck) m[n]++;
        res = m[deck[0]];
        for(auto n : m){
            res = gcd(res, n.second);
            if(res <= 1) return false;
        }
        return true;
    }
    int gcd(int num1, int num2){
        while(num2 != 0){
            int tmp = num1 % num2;
            num1 = num2;
            num2 = tmp;
        }
        return num1;
    }
    
};