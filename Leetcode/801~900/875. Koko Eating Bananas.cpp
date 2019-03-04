class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int hour, l, r, m;
        
        l = 1, r = 1000000000;
        while(l < r){
            hour = 0, m = (l + r) >> 1;
            for(int p : piles) hour += (int)ceil((float)p / m);
            if(hour > H) l = m + 1; else r = m;
        }
        
        return l;
    }
};