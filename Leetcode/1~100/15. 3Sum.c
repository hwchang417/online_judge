/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void bubble_sort(int *nums, int numsSize){
     int i, j, tmp, flag = 1;
     for(i = 1;i < numsSize && flag == 1;i++){
         flag = 0;
         for(j = 0;j < numsSize - i;j++){
             if(nums[j] > nums[j + 1]){
                 tmp = nums[j];
                 nums[j] = nums[j + 1];
                 nums[j + 1] = tmp;
                 flag = 1;
             }
         }
     }
 }
 
int** threeSum(int* nums, int numsSize, int* returnSize) {
    const int NUM_OF_SUM = 3;
    int i, j, z, m, n;
    int **sum_zero = NULL;
    int flag;
    bubble_sort(nums, numsSize);
    
    (*returnSize) = 0;
    for(i = 0;i < numsSize - 2;i++){
        for(j = i + 1;j < numsSize - 1;j++){
            for(z = j + 1;z < numsSize;z++){
                if(nums[i] + nums[j] + nums[z] == 0){
                    //search
                    flag = 0;
                    for(m = 0;m < (*returnSize);m++){
                        if(sum_zero[m][0] == nums[i] && sum_zero[m][1] == nums[j] && sum_zero[m][2] == nums[z]){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        int index = (*returnSize);
                        sum_zero = (int**)realloc(sum_zero, sizeof(int*) * (index + 1));
                        sum_zero[index] = (int*)malloc(sizeof(int) * NUM_OF_SUM);
                        sum_zero[index][0] = nums[i];
                        sum_zero[index][1] = nums[j];
                        sum_zero[index][2] = nums[z];
                        (*returnSize) = (*returnSize) + 1;
                    }
                }
            }
        }
    }
    
    return sum_zero;
}