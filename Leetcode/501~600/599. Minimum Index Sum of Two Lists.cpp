class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        int size, index, min;
        vector<string> res;
        string max_str;
        map<string, int> m1, m;
        
        index = 0;
        for(string s : list1)
            m1[s] = index++;
        
        index = 0;
        for(string s : list2){
            if(m1.find(s) != m1.end())
                m[s] = index + m1[s];
            index++;
        }
        
        min = INT_MAX;
        for(pair<string, int> p : m)
            if(min > p.second)
                min = p.second;
        
        for(pair<string, int> p : m)
            if(min == p.second)
                res.push_back(p.first);
        
        return res;
    }
};