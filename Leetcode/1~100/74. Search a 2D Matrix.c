bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	int i, j;
	int left, right;
	int top, down;
	int middleRow, middleCol;
	
	if(matrix == NULL || matrix[0] == NULL || matrixRowSize == 0 || matrixColSize == 0) return false;
	top = left = 0;
	right = matrixColSize - 1;
	down = matrixRowSize - 1;
    
	// search in row
	while(top <= down){
		middleRow = (top + down) >> 1;
		if(matrix[middleRow][0] <= target && matrix[middleRow][matrixColSize - 1] >= target){
			break;
		}else if(top == down){
			return false;
		}else if(matrix[middleRow][0] < target){
			top = middleRow + 1;
		}else if(matrix[middleRow][0] > target){
			down = middleRow - 1;
		}
	}
    
    if(top < 0 || down < 0 || top > down) return false;
	
	// search in column	
	while(left <= right){
		middleCol = (left + right) >> 1;
		if(matrix[middleRow][middleCol] == target){
			break;
		}else if(left == right){
			return false;
		}else if(matrix[middleRow][middleCol] < target){
			left = middleCol + 1;
		}else if(matrix[middleRow][middleCol] > target){
			right = middleCol - 1;
		}
	}
	
    if(left < 0 || right < 0 || left > right) return false;
    
	//printf("%d %d\n", middleRow, middleCol);
	
	return true;
}