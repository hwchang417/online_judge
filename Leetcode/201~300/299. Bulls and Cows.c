
#define foreach(index, size) for(index = 0;index < size;index++)
#define min(A, B) (A > B ? B : A)
char* getHint(char* secret, char* guess) {
    unsigned char S[10] = {0}, G[10] = {0};
    char* res;
    int A, total;
    int index, len;
    
    len = strlen(secret);
    foreach(index, len)
        S[secret[index] - '0']++, G[guess[index] - '0']++;
    
    A = 0;
    foreach(index, len)
        if(secret[index] == guess[index])
            A++;
    
    total = 0;
    foreach(index, 10)
        total += min(S[index], G[index]);
    
    res = (char*) calloc(sizeof(char), 8);
    sprintf(res, "%dA%dB", A, total - A);
    
    return res;
}