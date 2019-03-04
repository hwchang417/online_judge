class Solution {
public:
    char findTheDifference(string s, string t) {
        int size, index, sum;
        
        size = s.size();
        sum = t[size];
        for(index = 0;index < size;index++)
            sum ^= s[index], sum ^= t[index];
        
        return sum;
    }
};