class Solution {
public:
    struct CmpByValue {  
      bool operator()(const pair<int, int> & lhs, const pair<int, int> & rhs)
      {return lhs.second > rhs.second;}  
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int index, size;
        vector<int> res;
        vector<pair<int,int>>::iterator iter;
        map<int, int> m;
        
        size = nums.size();
        for(index = 0;index < size;index++){
            int tindex = nums[index];
            if(m.find(tindex) != m.end())
                m[tindex]++;
            else
                m[tindex] = 1;
        }
        
        vector<pair<int,int>> counts(m.begin(),m.end());
        sort(counts.begin(), counts.end(), CmpByValue());
        
        for(iter = counts.begin();iter != counts.end() && k > 0;k--, iter++)
            res.push_back(iter->first);
        
        return res;
    }
};