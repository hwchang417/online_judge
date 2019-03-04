class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int size;
        set<int> s;
        
        size = candies.size() >> 1;
        for(int n : candies){
            s.insert(n);
            if(s.size() >= size)
                return size;
        }
        
        return s.size();
    }
};