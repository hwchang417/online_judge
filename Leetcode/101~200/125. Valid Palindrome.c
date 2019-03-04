
bool isAlpha(char in){
    return (in >= 'A' && in <= 'Z') || (in >= 'a' && in <= 'z') || (in >= '0' && in <= '9');
}

char toLowerCase(char in){
    return (in >= 'A' && in <= 'Z' ? in - 'A' + 'a' : in);
}

bool isPalindrome(char* s) {
    int r, l, size;
    bool result;
    
    if(s[0] == '\0') return true;
    
    size = strlen(s);
    l = 0; r = size - 1;
    
    do{
        while(l < size && !isAlpha(s[l])) l++;
        
        while(r >= 0 && !isAlpha(s[r])) r--;
        
        if(l >= r || toLowerCase(s[l]) != toLowerCase(s[r])){
            break;
        }else{
            l++; r--;
        }
    }while(l < r);
    
    return l >= r;
}