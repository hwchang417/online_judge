
#define minNumber(a, b) (a >= b ? b : a)

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int k;
    int row, col, min;
    
    for(row = 1;row < triangleRowSize;row++){
        for(col = 0;col < triangleColSizes[row];col++){
            if(col == 0){
                min = triangle[row - 1][col];
            }else if(col == triangleColSizes[row] - 1){
                min = triangle[row - 1][col - 1];
            }else{
                min = minNumber(triangle[row - 1][col], triangle[row - 1][col - 1]);
            }
            triangle[row][col] += min;
        }
    }
    
    min = triangle[triangleRowSize - 1][0];
    for(col = 1;col < triangleColSizes[triangleRowSize - 1];col++){
        if(min > triangle[triangleRowSize - 1][col]){
            min = triangle[triangleRowSize - 1][col];
        }
    }
    
    return min;
}
