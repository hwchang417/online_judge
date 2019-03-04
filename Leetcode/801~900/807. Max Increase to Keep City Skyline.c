#include <stdio.h> 

int maxIncreaseKeepingSkyline(int** grid, int gridRowSize, int *gridColSizes) {
    int row, col, osum, nsum;
    int *rowMax, *colMax, max;
    
    max = 0;
    for(row = 0;row < gridRowSize;row++)
    	if(max < gridColSizes[row])
    	    max = gridColSizes[row];
    
    if(gridRowSize == 0 || max == 0) return 0;
    
    rowMax = (int*)calloc(gridRowSize, sizeof(int));
    colMax = (int*)calloc(max, sizeof(int));
    
    osum = 0;
    for(row = 0;row < gridRowSize;row++){
		for(col = 0;col < gridColSizes[row];col++){
			osum += grid[row][col];
		}
	}
	
    for(row = 0;row < gridRowSize;row++)
		for(col = 0;col < gridColSizes[row];col++){
			if(rowMax[col] < grid[row][col])
	    		rowMax[col] = grid[row][col];
			if(colMax[row] < grid[row][col])
	    		colMax[row] = grid[row][col];
		}
    
    for(row = 0;row < gridRowSize;row++){
		for(col = 0;col < gridColSizes[row];col++){
    		grid[row][col] = rowMax[col];
		}
	}
	
    for(row = 0;row < gridRowSize;row++){
		for(col = 0;col < gridColSizes[row];col++){
			if(grid[row][col] > colMax[row])
    			grid[row][col] = colMax[row];
		}
	}
	
    nsum = 0;
    for(row = 0;row < gridRowSize;row++){
		for(col = 0;col < gridColSizes[row];col++){
			nsum += grid[row][col];
		}
	}
    
    return nsum - osum;
}

