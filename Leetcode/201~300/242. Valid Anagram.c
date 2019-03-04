bool isAnagram(char* s, char* t) {
    int index;
    char table[26] = {0};
    
    while(*s != NULL)      table[*s - 'a']++, s++;
    while(*t != NULL)      table[*t - 'a']--, t++;
    
    for(index = 0;index < 26;index++)
        if(table[index] != 0) return false;
    
    return true;
}