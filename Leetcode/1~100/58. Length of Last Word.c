int lengthOfLastWord(char* s) {
    int size, prev_size;
    if(s == NULL || s[0] == '\0') return 0;
    
    prev_size = size = 0;
    while(s[0] != '\0'){
        if(s[0] != ' ')  prev_size++;
        else if(prev_size != 0) size = prev_size, prev_size = 0;
        s++;
    }
    
    if(prev_size != 0)
        size = prev_size;
    
    return size;
}