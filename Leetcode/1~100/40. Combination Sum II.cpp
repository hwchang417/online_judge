#include <algorithm>
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
		vector<int> combination;
		
		sort(candidates.begin(), candidates.end());
		combinationSum(candidates, combination, result, target, 0);
		
		return result;
    }
private:
	void combinationSum(vector<int>& candidates, 
						vector<int>& combination, 
						vector<vector<int>>& result, 
						int target, 
						int begin
						){
		if(target < 0){ return; }
        else if(!target){ result.push_back(combination); return;}
        
        for(int i = begin;i < candidates.size();i++){
			if(i > begin && candidates[i] == candidates[i - 1]) continue;
			if(candidates[i] <= target){
				combination.push_back(candidates[i]);
				combinationSum(candidates, combination, result, target - candidates[i], i+1);
				combination.pop_back();
			}
        }
	
	}
	
};