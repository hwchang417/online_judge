bool isExist(char** board, int boardRowSize, int boardColSize, char* word, int x, int y){
	bool res = false;
	char tmp;
	
    if(*word == -1)
        return false;
    
	if(*word == '\0')
		return true;
	
	if(*(word + 1) == '\0' && board[y][x] == *word)
	    return true;
	
	if(board[y][x] != *word)
		return false;

	tmp = board[y][x];
	board[y][x] = -1;
	if(y > 0 && !res){
		res |= isExist(board, boardRowSize, boardColSize, word + 1, x, y - 1);
	}
	
	if(y < boardRowSize - 1 && !res){
		res |= isExist(board, boardRowSize, boardColSize, word + 1, x, y + 1);
	}
	
	if(x > 0 && !res){
		res |= isExist(board, boardRowSize, boardColSize, word + 1, x - 1, y);
	}
	
	if(x < boardColSize - 1 && !res){
		res |= isExist(board, boardRowSize, boardColSize, word + 1, x + 1, y);
	}
	board[y][x] = tmp;
	
	return res;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
	int i, j, k;
    
    for(i = 0;i < boardRowSize;i++){
    	for(j = 0;j < boardColSize;j++){
			if(isExist(board, boardRowSize, boardColSize, word, j, i))
				return true;
		}
	}
	return false;
}
