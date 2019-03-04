class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int index, sub_size, all_size, nth;
        vector<int> res;
        
        all_size = nums.size();
        sub_size = findNums.size();
        for(index = 0;index < sub_size;index++){
            int num2find = findNums[index];
            nth = 0;
            //do linear search with num2find variable
            while(nth < all_size && num2find != nums[nth]) nth++;
            //find the next greater element
            while(nth < all_size && num2find >= nums[nth]) nth++;
            //if it was found, push it into result vector
            //if not, push -1 into result vector
            if(nth == all_size) res.push_back(-1);
            else res.push_back(nums[nth]);
        }
        
        return res;
    }
};