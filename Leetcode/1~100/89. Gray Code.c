
int* grayCode(int n, int* returnSize){
	
	int *res, i, j, index, end;
	
	*returnSize = 1 << n;
	res = (int*)malloc(sizeof(int) * *returnSize);
	
	res[0] = 0;
	index = end = 1;
	
	for(i = 1;i <= n;i++){
		for(j = end - 1;j >= 0;j--){
			res[index] = res[j] | (1 << (i - 1));
			index++;
		}
		end = index;
	}
	
    return res;
}
