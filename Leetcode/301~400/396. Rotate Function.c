int maxRotateFunction(int* A, int ASize) {
    int max, index;
    long long int sum, f;
    
    if(A == NULL || ASize == 0) return 0;
    
    f = sum = 0;
    for(index = 0;index < ASize;index++){
        sum += A[index];
        f += index * A[index];
    }
    
    max = f;
    f = f + sum - ASize * A[ASize - 1];
    for(index = 1;index < ASize;index++){
        f = f + sum - ASize * A[ASize - index - 1];
        if(f > max) max = f;
    }
    
    return max;
}