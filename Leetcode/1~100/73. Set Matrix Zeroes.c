
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int row, col;
    int zRow = 0, zCol = 0;
    
    for(row = 0;row < matrixRowSize;row++)
    	for(col = 0;col < matrixColSize;col++)
    		if(matrix[row][col] == 0){
    			if(row == 0) zRow = 1;
    			if(col == 0) zCol = 1;
    			matrix[row][0] = matrix[0][col] = 0;
			}
	
    for(row = 1;row < matrixRowSize;row++)
    	for(col = 1;col < matrixColSize;col++)
    		if(matrix[row][0] == 0 || matrix[0][col] == 0){
    			matrix[row][col] = 0;
			}
			
    if(zCol){
	    for(row = 0;row < matrixRowSize;row++)
	    	matrix[row][0] = 0;
	}
    
    if(zRow){
    	for(col = 0;col < matrixColSize;col++)
    		matrix[0][col] = 0;
	}
}
