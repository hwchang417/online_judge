class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int index, size;
        int start, end;
        string str;
        vector<string> res;
        
        size = nums.size();
        if(size == 0) return res;
        
        end = start = nums[0];
        for(index = 1;index < size;index++){
            
            if(end == nums[index] - 1){
                end = nums[index];
            }else{
                str = to_string(start);
                if(start != end)    
                    str += "->" + to_string(end);
                
                res.push_back(str);
                start = end = nums[index];
            }
        }
        
        str = to_string(start);
        if(start != end)    
            str += "->" + to_string(end);
        res.push_back(str);
        
        return res;
    }
};