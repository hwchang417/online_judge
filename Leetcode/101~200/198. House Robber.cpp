
#define max(a, b) (a > b ? a : b)
class Solution {
public:
    int rob(vector<int>& nums) {
        int index, size;
        int tmpRob, tmpNotRob;
        int lastRob, lastNotRob;
        
        size = nums.size();
        lastNotRob = lastRob = tmpRob = tmpNotRob = 0;
        for(index = 0;index < size;index++){
            tmpRob = lastNotRob + nums[index];
            tmpNotRob = lastNotRob > lastRob ? lastNotRob : lastRob;
            lastRob = tmpRob;
            lastNotRob = tmpNotRob;
        }
        
        return lastNotRob > lastRob ? lastNotRob : lastRob;
    }
    
    int rob2(vector<int>& nums) {
        int index, size, res, num1, num2;
        size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);
        
        res = nums[2] + nums[0];
        nums[2] = res;
        res = max(res, nums[1]);
        for(index = 3;index < size;index++){
            int total = nums[index] + max(nums[index - 2], nums[index - 3]);
            nums[index] = total;
            res = max(res, total);
        }
        return res;
    }
    
//     int robHome(vector<int>& nums, int index){
//         if(index >= nums.size()) return 0;
//         int move2step, move3step;
//         move2step = robHome(nums, index + 2);
//         move3step = robHome(nums, index + 3);
        
//         return nums[index] + (move2step > move3step ? move2step : move3step);
//     }
    
//     int rob(vector<int>& nums) {
//         int first, second;
//         first = robHome(nums, 0);
//         second = robHome(nums, 1);
//         return first > second ? first : second;
//     }
};