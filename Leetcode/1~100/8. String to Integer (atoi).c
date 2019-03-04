int myAtoi(char* str) {
    int result = 0;
    long long int tmp_result = 0;
    int neg = 0;
    int i = 0, j;
    int size = strlen(str);
    int flag = 0;
    
    const long long int int_upper = 2147483647;
    const long long int int_lower = -2147483648;
    const long long int longlong_int_upper = 9223372036854775807;
    const long long int longlong_int_lower = -9223372036854775808;
    
    //check if it is valid
    for(j = 0;j < size;j++){
        if(str[j] == '+'){
            flag++;
            i++;
        }else if(str[j] == '-'){
            flag++;
            i++;
            neg = 1;
        }else if(str[j] == ' '){
            if(flag == 1) return 0;
            i = j + 1;
        }else if(str[j] >= '0' && str[j] <= '9'){
            break;
        }
        if(flag == 2) return 0;
    }
    
    for(;i < size;i++){
        if(str[i] >= '0' && str[i] <= '9'){
            tmp_result = ((tmp_result << 3) + (tmp_result << 1)) + (str[i] - '0');
            if(neg == 0 && tmp_result > int_upper){
                result = int_upper;
                return result;
            }else if(neg == 1 && -tmp_result < int_lower){
                result = int_lower;
                return result;
            }
        }else break;
    }
    
    tmp_result = neg == 1 ? - tmp_result : tmp_result;
    result = (int)tmp_result;
    
    return result;
}