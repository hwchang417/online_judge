void moveZeroes(int* nums, int numsSize) {
    int zero, nonzero;
    
    for(zero = 0;zero < numsSize;zero++){
        if(!nums[zero]){
            nonzero = zero + 1;
            while(nonzero < numsSize && !nums[nonzero]) nonzero++;
            if(nonzero != numsSize){
                nums[zero] = nums[nonzero];
                nums[nonzero] = 0;
            }
        }
    }
    
}