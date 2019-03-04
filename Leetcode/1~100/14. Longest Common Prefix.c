char* longestCommonPrefix(char** strs, int strsSize) {
    int i, j;
    int pre_len = 0;
    char c;
    char *prefix = "";
    if(strs == NULL || strs[0] == NULL) return prefix;
    for(i = 0;strs[0][i] != NULL;i++){
        c = strs[0][i];
        for(j = 1;j < strsSize;j++){
            if(c != strs[j][i]){
                prefix = (char*)malloc(sizeof(char) * (pre_len + 1));
                memcpy(prefix, strs[0], sizeof(char) * pre_len);
                prefix[pre_len] = '\0';
                return prefix;
            }
        }
        pre_len++;
    }
    
    prefix = (char*)malloc(sizeof(char) * (pre_len + 1));
    memcpy(prefix, strs[0], sizeof(char) * pre_len);
    prefix[pre_len] = '\0';
    return prefix;
}