char* longestPalindrome(char* s) {
    int i;
    int len = strlen(s);
    int start, end;
    int max = 1;
    int max_start = 0, max_end = 0;
    char *result;
    
    for(i = 0;i < len;i++){
        //one condition
        start = i;
        if(start < len - 1 && s[start] == s[start + 1]){
            end = start + 2;
            start--;
        }else{
            continue;
        }
        
        while(start >= 0 && end < len){
            if(s[start] != s[end]) break;
            start--;
            end++;
        }
        
        if(end - start - 1 > max){
            max = end - start - 1;
            max_start = start + 1;
            max_end = end - 1;
        }
    }
    
    for(i = 0;i < len;i++){
        //one condition
        start = i;
        if(start >= 1 && start + 1 < len && s[start - 1] == s[start + 1]){
            end = start + 2;
            start = start - 2;
        }else{
            continue;
        }
        
        while(start >= 0 && end < len){
            if(s[start] != s[end]) break;
            start--;
            end++;
        }
        
        if(end - start - 1 > max){
            max = end - start - 1;
            max_start = start + 1;
            max_end = end - 1;
        }
    }
    
    result = (char*)malloc((max + 1) * sizeof(char));
    memcpy(result, s + max_start, sizeof(char) * max);
    result[max] = '\0';
    return result;
}