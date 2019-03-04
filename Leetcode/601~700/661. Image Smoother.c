/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int* i1D(int rowSize){
    int* res;
    res = (int*) calloc(rowSize, sizeof(int));
    return res;
}

int** i2D(int rowSize, int colSize){
    int row;
    int** res = (int**) calloc(rowSize, sizeof(int*));
    for(row = 0;row < rowSize;row++)
        res[row] = i1D(colSize);
    return res;
}

int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize) {
    int index, row, col, m, n, sum, cnt, lastRow, lastCol, lastSecRow, lastSecCol;
    int** result;
    result = i2D(MRowSize, MColSize);
    
    for(row = 0;row < MRowSize;row++){
        for(col = 0;col < MColSize;col++){
            cnt = sum = 0;
            for(m = -1;m <= 1;m++){
                int r = row + m;
                for(n = -1;n <= 1;n++){
                    int c = col + n;
                    if(r < 0 || r > MRowSize - 1 || c < 0 || c > MColSize - 1)
                        continue;
                    sum += M[r][c];
                    cnt++;
                }
            }
            result[row][col] = sum / cnt;
        }
    }
            
    *returnSize = MRowSize;
    *columnSizes = i1D(MRowSize);
    for(index = 0;index < MRowSize;index++)
        (*columnSizes)[index] = MColSize;
    return result;
}