bool isInterleave(char* s1, char* s2, char* s3) {
    bool res = false;
    if(*s3 == '\0') return *s1 == '\0' && *s2 == '\0';
    if(s1 && *s1 == *s3)
        res = isInterleave(s1 + 1, s2, s3 + 1);
    if(!res && s2 && *s2 == *s3)
        res = isInterleave(s1, s2 + 1, s3 + 1);
    return res;
}