class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int index, size;
        vector<int> res;
        
        for(int n : A)
            if((n & 0x01) == 0)
                res.push_back(n);
        
        for(int n : A)
            if((n & 0x01) == 1)
                res.push_back(n);
        
        return res;
    }
};