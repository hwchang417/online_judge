typedef struct {
    int rowSize;
    int colSize;
    int** integral;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    int row, col;
    NumMatrix* m = (NumMatrix*) malloc(sizeof(NumMatrix));
    m->rowSize = matrixRowSize;
    m->colSize = matrixColSize;
    
    m->integral = (int**) malloc(sizeof(int*) * matrixRowSize);
    for(row = 0;row < matrixRowSize;row++)
        m->integral[row] = (int*) malloc(sizeof(int) * matrixColSize);
    
    m->integral[0][0] = matrix[0][0];
    for(col = 1;col < matrixColSize;col++)
        m->integral[0][col] = matrix[0][col] + m->integral[0][col - 1];
    
    for(row = 1;row < matrixRowSize;row++)
        m->integral[row][0] = matrix[row][0] + m->integral[row - 1][0];
    
    for(row = 1;row < matrixRowSize;row++)
        for(col = 1;col < matrixColSize;col++)
            m->integral[row][col] = matrix[row][col] + m->integral[row][col - 1] + 
                                    m->integral[row - 1][col] - m->integral[row - 1][col - 1];
    
    return m;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    if(row1 == 0 && col1 == 0) return obj->integral[row2][col2];
    else if(row1 == 0) return obj->integral[row2][col2] - obj->integral[row2][col1 - 1];
    else if(col1 == 0) return obj->integral[row2][col2] - obj->integral[row1 - 1][col2];
    return obj->integral[row2][col2] + obj->integral[row1 - 1][col1 - 1] - obj->integral[row1 - 1][col2] - obj->integral[row2][col1 - 1];
}

void numMatrixFree(NumMatrix* obj) {
    int row;
    for(row = 0;row < obj->rowSize;row++)
        free(obj->integral[row]);
    
    free(obj->integral);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * struct NumMatrix* obj = numMatrixCreate(matrix, matrixRowSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 * numMatrixFree(obj);
 */