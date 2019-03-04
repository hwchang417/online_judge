class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i, j, size, prev;
        map<int, vector<pair<int, int>>> m;
        map<int, bool> visit;
        vector<pair<int, int>>::iterator iter;
        vector<vector<int>> res;
        
        
        size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = size-1; i > 0; i--){
            if(i < size - 1 && nums[i] == nums[i+1]) continue;
            for(int j = i - 1; j > -1; j--){
                if(j < i - 1 && nums[j] == nums[j+1]) continue;
                m[nums[i] + nums[j]].push_back(pair<int, int>(j,i));
            }
        }
        
        for(int i = 0;i < size;i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1;j < size;j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;                    
                int remain = target - nums[i] - nums[j];
                if(m.count(remain)){
                    for(iter = m[remain].begin();iter != m[remain].end();iter++){
                        int k = iter->first, l = iter->second;
                        if(k > j){
                            vector<int> element = {nums[i], nums[j], nums[k], nums[l]};
                            
                            if(!res.empty() && 
                               res.back()[0] == element[0] && 
                               res.back()[1] == element[1] && 
                               res.back()[2] == element[2] && 
                               res.back()[3] == element[3]){
                                continue;
                            }
                            
                            res.push_back(element);
                        }
                    }
                    
                }
                
            }
        }
        
        return res;
    }
};