bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int i, j, k, l;
    char c;
    int index;
    const int valid_arr_size = sizeof(int) * 9;
    int arr_valid[9];
    
    //row-check
    for(i = 0;i < 9;i++){
        memset(arr_valid, 0, valid_arr_size);
        for(j = 0;j < 9;j++){
            c = board[i][j];
            if(c != '.'){
                index = c - '0' - 1;
                if(arr_valid[index] == 1)
                    return false;
                arr_valid[index] = 1;
            }
        }
    }
    
    //col-check
    for(i = 0;i < 9;i++){
        memset(arr_valid, 0, valid_arr_size);
        for(j = 0;j < 9;j++){
            c = board[j][i];
            if(c != '.'){
                index = c - '0' - 1;
                if(arr_valid[index] == 1)
                    return false;
                arr_valid[index] = 1;
            }
        }
    }
    
    //each 3x3 check
    for(i = 0;i < 9;i+=3){
        for(j = 0;j < 9;j+=3){
            memset(arr_valid, 0, valid_arr_size);
            for(k = 0;k < 3;k++){
                for(l = 0;l < 3;l++){
                    c = board[i + k][j + l];
                    if(c != '.'){
                        index = c - '0' - 1;
                        if(arr_valid[index] == 1)
                            return false;
                        arr_valid[index] = 1;
                    }
                }
            }
        }
    }
    
    return true;
}