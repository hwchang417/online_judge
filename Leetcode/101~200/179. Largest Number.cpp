class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> strs;
        
        for(int n : nums)
            strs.push_back(to_string(n));
        
        sort(strs.begin(), strs.end(), [](string &s1, string &s2){ return s1 + s2 > s2 + s1; });
        
        //add all number
        for(string s : strs)
            res += s;
        
        //eliminates extra zeros in front of the number
        while(res.size() > 1 && res[0] == '0'){
            res.erase(0, 1);
        }
        
        return res;
    }
};