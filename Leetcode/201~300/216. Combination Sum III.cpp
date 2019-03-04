class Solution {
public:
    
    void dfs(vector<vector<int>>& res, vector<int>& current, int start, int size, int n){
        if(size < 0 || n < 0) return;
        if(size == 0 && n == 0) res.push_back(current);
        
        for(int index = start;index <= 9;index++){
            current.push_back(index);
            dfs(res, current, index + 1, size - 1, n - index);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> res;
        dfs(res, curr, 1, k, n);
        return res;
    }
};