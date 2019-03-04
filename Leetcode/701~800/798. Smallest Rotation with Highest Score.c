
int bestRotation(int* A, int ASize) {
    int i, j, count, max, max_index;
	int* minus, *add;
	
	minus = (int*)calloc((ASize+5), sizeof(int));
    add = (int*)calloc((ASize+5), sizeof(int));
    count = 0;
    for(i = 0;i < ASize;i++){
    	if(i >= A[i]){
    		count++;
    		minus[i - A[i] + 1] ++;
    		add[i + 1]++;
		}else{
			add[i + 1]++;
			minus[i + ASize - A[i] + 1]++;
		}
	}
    
    max = count;
    max_index = 0;
    for(i = 1;i < ASize;i++){
    	count += add[i];
    	count -= minus[i];
    	if(max < count){
    		max = count;
			max_index = i;
		}
	}
    
    free(add);
    free(minus);
    
    return max_index;
}