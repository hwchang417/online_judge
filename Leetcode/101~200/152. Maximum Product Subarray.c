
#define Min(a, b) (a > b ? b : a)
#define Max(a, b) (a > b ? a : b)
int maxProduct(int* nums, int numsSize) {
    
    int index, maxt, mint, max;
    
    max = mint = maxt = nums[0];
    
    for(index = 1;index < numsSize;index++){
        
        if(nums[index] > 0){
            maxt = maxt <= 0 ? nums[index] : nums[index] * maxt;
            mint = mint <= 0 ? nums[index] * mint : nums[index];
        }else{
            int temp_max, temp_min;
            
            temp_min = mint * nums[index];
            temp_max = maxt * nums[index];
            
            maxt = maxt > 0 ? Max(nums[index], temp_min) : temp_min;
            mint = mint > 0 ? temp_max : Min(nums[index], temp_max);
        }
        
        if(maxt > max)
            max = maxt;
    }
    
    return max;
}