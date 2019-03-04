class Solution {
public:
    //method1: hash, O(n)
    //method2: sort first, and check if the consecutive repeated elements exist, O(nlogn + n)
    //method3: try to sort array and check if there is any repeated number exist, O(n^2)
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int index = 1;index < size;index++){
            if(nums[index - 1] == nums[index])
                return true;
        }
        
        return false;
    }
};