class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long int first_max, second_max, third_max, size, index;
        
        first_max = second_max = third_max = LLONG_MIN;
        size = nums.size();
        for(index = 0;index < size;index++){
            if(first_max < nums[index]){
                third_max = second_max;
                second_max = first_max;
                first_max = nums[index];
            }else if(first_max > nums[index]){
                if(second_max < nums[index]){
                    third_max = second_max;
                    second_max = nums[index];
                }else if(second_max > nums[index]){
                    if(third_max < nums[index])
                        third_max = nums[index];
                }
            }
        }
        
        return third_max == LLONG_MIN ? first_max : third_max;
    }
};