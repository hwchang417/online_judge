class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
           vector<vector<int>> res;
           vector<int> combination;
           sort(candidates.begin(), candidates.end());
           combinationSum(candidates, combination, res, target, 0);
           
           return res;
    }
private:
    void combinationSum(vector<int>& candidates, vector<int> &combination, vector<vector<int>> &res, int target, int begin){
        if(!target){ res.push_back(combination);}
        
        for(int i = begin;i < candidates.size() && target >= candidates[i];i++){
            combination.push_back(candidates[i]);
            combinationSum(candidates, combination, res, target - candidates[i], i);
            combination.pop_back();
        }
    }
    
};