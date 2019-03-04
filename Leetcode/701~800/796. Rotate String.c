
bool rotateString(char* A, char* B) {
    int i, j, start;
	int sizeA, sizeB;
    sizeB = strlen(B);
	sizeA = strlen(A);
	
	if(sizeA != sizeB) return false;
	
	for(j = 0;j < sizeB;j++){
		if(A[0] == B[j]){
			i = 1;
			start = j + 1;
			while(i < sizeA && start < sizeA && A[i] == B[start]){
				start = (start + 1) % sizeB;
				i++;
			}
			
			if(i == sizeA)
				return true;
		}
	}
    
    return false;
}