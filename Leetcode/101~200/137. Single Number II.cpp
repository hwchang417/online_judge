class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int index, size;
        map<int, int> hash;
        map<int, int>::iterator iter;
        size = nums.size();
        
        for(index = 0;index < size;index++){
            iter = hash.find(nums[index]);
            if(iter != hash.end())
                iter->second++;
            else
                hash[nums[index]] = 1;
        }
        
        for(iter = hash.begin();iter != hash.end();iter++)
            if(iter->second == 1)
                return iter->first;
        
        return -1;
    }
};