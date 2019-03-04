
int isVowels(char in){
    return in == 'a' || in == 'e' || in == 'i' || in == 'o' || in == 'u' ||
            in == 'A' || in == 'E' || in == 'I' || in == 'O' || in == 'U';
}

char* reverseVowels(char* s) {
    int head, tail;
    int len;
    char tmp;
    
    len = strlen(s);
    head = 0; tail = len - 1;
    
    while(head < tail){
        //find position of vowel
        while(head < len && !isVowels(s[head])) head++;
        while(tail >= 0 && !isVowels(s[tail])) tail--;
        
        //break while loop if head and tail are crossed each other or illegal index of array
        if(head >= tail || tail < 0 || head >= len) break;

        //swap variable
        tmp = s[head];
        s[head++] = s[tail];
        s[tail--] = tmp;
    }
    
    return s;
}