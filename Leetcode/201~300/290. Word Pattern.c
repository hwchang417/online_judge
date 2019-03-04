bool wordPattern(char* pattern, char* str) {
    const int MAX_token = 26;
    int i, j;
    char *delim = " ";
    char *pattern_token[MAX_token];
    char *ptr;
    
    for(j = 0;j < MAX_token;j++) pattern_token[j] = NULL;
    
    i = 0;
    ptr = strtok(str, delim);
    while(ptr != NULL){
        if(pattern[i] == NULL) return false;
        
        int index = pattern[i++] - 'a';
        if(pattern_token[index] != NULL){
            
            if(strcmp(pattern_token[index], ptr) != 0) return false;
            
        }else{
            
            for(j = 0;j < MAX_token;j++){
                if(pattern_token[j] != NULL && strcmp(pattern_token[j], ptr) == 0) return false;
            }
            
            int size = strlen(ptr) + 1; //for '\0' character
            pattern_token[index] = (char*) malloc(sizeof(char) * size);
            if(pattern_token[index] == NULL) return false;
            
            strcpy(pattern_token[index], ptr);
        }
        ptr = strtok(NULL, delim);
    }
    
    //release
    for(j = 0;j < MAX_token;j++) if(pattern_token[j] != NULL) free(pattern_token[j]);
    
    return pattern[i] == NULL;
}