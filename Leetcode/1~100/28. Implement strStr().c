int strStr(char* haystack, char* needle) {
    int index, size;
    char *str, *search;
    if(needle == NULL) return -1;
    if(haystack == NULL) return -1;
    if(*haystack == NULL && *needle == NULL) return 0;
    if(*haystack == NULL) return -1;
    if(*needle == NULL) return 0;
    
    size = strlen(haystack) - strlen(needle);
    index = 0;
    while(*haystack != NULL && index <= size){
        str = haystack;
        search = needle;
        while((*str != NULL && *search != NULL) && *str == *search) str++, search++;
        if(*search == NULL) return index;
        index++;
        haystack++;
    }
    
    return -1;
}