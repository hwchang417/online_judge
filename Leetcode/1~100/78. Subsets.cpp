class Solution {
public:
    
    void combination(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp, int size, int depth, int start){
        int i;
        if(depth == size){
            res.push_back(temp);
        }
        
        for(i = start;i < nums.size();i++){
            temp.push_back(nums[i]);
            combination(res, nums, temp, size, depth + 1, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int i;
        int size = nums.size();
        vector<int> temp;
        vector<vector<int>> res;
        
        res.push_back(temp);
        
        for(i = 1;i <= size;i++)
            combination(res, nums, temp, i, 0, 0);
       
        
        return res;
    }
};