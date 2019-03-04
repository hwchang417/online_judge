class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i = digits.size();i--;digits[i] = 0)
            if(digits[i]++ < 9)
                return digits;
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};