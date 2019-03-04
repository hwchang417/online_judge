#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt;

/*void swap(int *num1, int *num2){
	*num1 = (*num1) ^ (*num2);
	*num2 = (*num1) ^ (*num2);
	*num1 = (*num1) ^ (*num2);
}*/

void swap(int *num1, int *num2){
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void per(int* nums, int begin, int numsSize, int **result){
	int i;
	if(begin >= numsSize){
		memcpy(result[cnt++], nums, numsSize * sizeof(int));
		return;
	}
	
	for(i = begin;i < numsSize;i++){
		swap(&nums[begin], &nums[i]);
		per(nums, begin + 1, numsSize, result);
		swap(&nums[begin], &nums[i]);
	}
}

int** permute(int* nums, int numsSize, int* returnSize) {
	int i;
    int** result;
    int max_permutaion;
    
    max_permutaion = 1;
    
    for(i = 2;i <= numsSize;i++)
		max_permutaion *= i;
    
    result = (int**)calloc(max_permutaion, sizeof(int*));
    for(i = 0;i < max_permutaion;i++)
    	result[i] = (int*)calloc(numsSize, sizeof(int));
    	
    cnt = 0;
    per(nums, 0, numsSize, result);
    
    *returnSize = max_permutaion;
    return result;
}
