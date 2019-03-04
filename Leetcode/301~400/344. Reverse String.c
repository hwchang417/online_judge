char* reverseString(char* s) {
    int i;
    int size_1 = strlen(s) - 1;
    char *r = (char*)malloc(sizeof(char) * (size_1 + 2));
    
    for(i = 0;i <= size_1;i++){
        r[i] = s[size_1 - i];
    }
    
    r[size_1 + 1] = '\0';
    return r;
}