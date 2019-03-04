int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
	int i, j;
	
	for(i = 0;i < obstacleGridRowSize;i++)
		for(j = 0;j < obstacleGridColSize;j++)
  		    obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? -1 : 0;
	
	if(obstacleGrid[0][0] == -1) return 0;
	
	obstacleGrid[0][0] = 1;
	
	for(i = 1;i < obstacleGridRowSize;i++)
	    if(obstacleGrid[i][0] != -1)
		    obstacleGrid[i][0] = obstacleGrid[i - 1][0];
			
	for(i = 1;i < obstacleGridColSize;i++)
	    if(obstacleGrid[0][i] != -1)
		    obstacleGrid[0][i] = obstacleGrid[0][i - 1];
	
	for(i = 1;i < obstacleGridRowSize;i++){
		for(j = 1;j < obstacleGridColSize;j++){
			if(obstacleGrid[i][j] == -1)
			    continue;
			if(obstacleGrid[i - 1][j] != -1)
			    obstacleGrid[i][j] += obstacleGrid[i - 1][j];
			if(obstacleGrid[i][j - 1] != -1)
			    obstacleGrid[i][j] += obstacleGrid[i][j - 1];
		}
	}
	
    return obstacleGrid[obstacleGridRowSize - 1][obstacleGridColSize - 1] == -1 ? 0 : obstacleGrid[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}
