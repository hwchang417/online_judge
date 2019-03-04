#include <string.h>

int lengthOfLongestSubstring(char* s) {
    
    int i, j, z;
    int start, end;
    int size = strlen(s);
    int max = 0;
    if(size <= 1) return size;
    
    for(start = 0, end = 1;end < size;end++){
        for(i = start;i < end;i++){
            if(s[i] == s[end]){
                if(end - start > max) max = end - start;
                start = i + 1;
                break;
            }
        }
    }
    if(end - start > max) max = end - start;
    
    return max;
}