int singleNumber(int* nums, int numsSize) {
    int sum = 0;
    int end = nums + numsSize;
    
    for(;nums != end;nums++)
        sum ^= (*nums);
    
    return sum;
}