char* convert(char* s, int numRows) {
    
    int i, j, acc;
    int int0 = numRows > 1 ? (numRows - 1) * 2 : 1;
    int int1 = (numRows - 2) * 2;
    int int2 = 2;
    int flag;
    int size = strlen(s);
    char *result = (char*)malloc(sizeof(char) * (size + 1));
    j = 0;
    if(numRows > 1){
        //with two interval
        for(i = 0;i < numRows;i++){
            if(i == 0 || i == numRows - 1){
                for(acc = i;acc < size;acc += int0)
                    result[j++] = s[acc];
            }else{
                flag = 0;
                for(acc = i;acc < size;){
                    result[j++] = s[acc];
                    if(flag == 0){
                         flag = 1;
                         acc += int1;
                    }
                    else{
                         flag = 0;
                         acc += int2;
                    }
                }
                int1 -= 2;
                int2 += 2;
            }
        }
    }else{
        //no interval
        for(i = 0;i < numRows;i++){
            if(i == 0 || i == numRows - 1){
                for(acc = i;acc < size;acc += int0)
                    result[j++] = s[acc];
            }
        }
    }
    result[size] = '\0';
    return result;
}