
int cnt;
void computation(int **res, int *temp, int n, int k, int depth, int num){
	int i;
	
	if(depth == k){
		memcpy(res[cnt++], temp, sizeof(int) * k);
		return;
	}
	
	for(i = num;i <= n;i++){
		temp[depth] = i;
		computation(res, temp, n, k, depth + 1, i + 1);
	}
}

int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int i;
	int num, denom, total, tmpk;
	int **res;
	int *temp;
	
	if(n == 0 || k == 0) return NULL;
	
	tmpk = k;
	if(n - k < k) tmpk = n - k;
	
    num = denom = 1;
    for(i = 0;i < tmpk;i++)
    	num *= (n - i), denom *= (i + 1);
   	total = num / denom;
   	
   	//allocate memory
   	res = (int**)calloc(total, sizeof(int*));
   	for(i = 0;i < total;i++)
   		res[i] = (int*)calloc(k, sizeof(int));
   	
   	*returnSize = total;
   	*columnSizes = (int*)malloc(sizeof(int) * total);
   	for(i = 0;i < total;i++)
   		(*columnSizes)[i] = k;
   	
   	temp = (int*)malloc(sizeof(int) * k);
   	
   	//printf("%d\n", total);
   	cnt = 0;
	computation(res, temp, n, k, 0, 1);

   	free(temp);
   	return res;
}
