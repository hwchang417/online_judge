
int** generateMatrix(int n) {
	int i, cnt;
	int left, right, bottom, top;
    int** result;
    
    if(n == 0) return NULL;
    
    result = (int**)malloc(n * sizeof(int*));
    for(i = 0;i < n;i++)
    	result[i] = (int*)malloc(n * sizeof(int));
	
	cnt = 1;
	left = top = 0;
	right = bottom = n - 1;
	
	while(top <= bottom && left <= right){
		for(i = left;i <= right;i++)
			result[top][i] = cnt++;
		
		top++;
		if(top > bottom) break;
		for(i = top;i <= bottom;i++)
			result[i][right] = cnt++;
		
		right--;
		if(left > right) break;
		for(i = right;i >= left;i--)
			result[bottom][i] = cnt++;

		bottom--;
		if(top > bottom) break;
		for(i = bottom;i >= top;i--)
			result[i][left] = cnt++;

		left++;
	}
	
    return result;
}