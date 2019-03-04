
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
    int i, units, lines, size;
	int* res;
    res = (int*)malloc(sizeof(int) * 2); 
    
    i = size = units = lines = res[0] = res[1] = 0;
    *returnSize = 2;
    if(S == NULL) return res;
    while(S[i++] != '\0');
    
    size = i - 1;
    for(i = 0;i < size;i++){
    	int cnt = widths[S[i] - 'a'];
    	if(units + cnt > 100)
			units = cnt, lines++;
    	else
    		units += cnt;
	}
    
    res[0] = lines + (units ? 1 : 0);
    res[1] = units;
    
    return res;
}
