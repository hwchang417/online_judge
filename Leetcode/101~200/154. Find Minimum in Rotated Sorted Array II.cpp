class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int index, size;
        
        //搜尋策略
        //如果前後數字變大，則找到變小的那個瞬間
        //如果走訪完整個陣列前後數字都是變大，則輸出第一個數字
        size = nums.size();
        
        for(index = 1;index < size;index++){
            if(nums[index - 1] > nums[index]){
                return nums[index];
            }
        }
        return nums[0];
    }
};