
#include <string.h>

int isEmail(char* S, int size){
    int index;
    
    for(index = 0;index < size;index++){
        if(S[index] == '@'){
            return 1;
        }
    }
    return 0;
}

int nameSize(char* S, int size){
    int index;
    for(index = 0;index < size && S[index] != '@';index++);
    return index;
}

char toLowercase(char in){
    return (in >= 'A' && in <= 'Z' ? in - 'A' + 'a' : in);
}

int isDigit(char ch){
    return ch >= '0' && ch <= '9';
}

char* countryCode11(char* S, int size){
    int dash[] = {2, 6, 10};
    char* res;
    int index, cs, dash_cnt;
    dash_cnt = 0;
    
    res = (char*)malloc(16 * sizeof(char));
    
    res[0] = '+';
    cs = 1;
    for(index = 0;index < size;index++){
        if(isDigit(S[index])){
            if(cs == dash[dash_cnt]){
                res[cs++] = '-';
                if(dash_cnt != 2) dash_cnt++;
            }
            res[cs++] = (cs <= 10 ? '*' : S[index]); 
        }
    }
    res[15] = '\0';
    
    return res;
}

char* countryCode13(char* S, int size){
    int dash[] = {4, 8, 12};
    char* res;
    int index, cs, dash_cnt;
    dash_cnt = 0;
    
    res = (char*)malloc(18 * sizeof(char));
    
    res[0] = '+';
    cs = 1;
    for(index = 0;index < size;index++){
        if(isDigit(S[index])){
            if(cs == dash[dash_cnt]){
                res[cs++] = '-';
                if(dash_cnt != 2) dash_cnt++;
            }
            res[cs++] = (cs <= 12 ? '*' : S[index]); 
        }
    }
    res[17] = '\0';
    
    return res;
}

char* countryCode(char* S, int size){
    int dash[] = {3, 7, 11};
    char* res;
    int index, cs, dash_cnt;
    dash_cnt = 0;
    
    res = (char*)malloc(17 * sizeof(char));
    
    res[0] = '+';
    cs = 1;
    for(index = 0;index < size;index++){
        if(isDigit(S[index])){
            if(cs == dash[dash_cnt]){
                res[cs++] = '-';
                if(dash_cnt != 2) dash_cnt++;
            }
            res[cs++] = (cs <= 11 ? '*' : S[index]); 
        }
    }
    res[16] = '\0';
    
    return res;
}

char* noCountryCode(char* S, int size){
    int dash[] = {3, 7};
    char* res;
    int index, cs, dash_cnt;
    cs = dash_cnt = 0;
    
    res = (char*)malloc(13 * sizeof(char));
    
    for(index = 0;index < size;index++){
        if(isDigit(S[index])){
            if(cs == dash[dash_cnt]){
                res[cs++] = '-';
                if(dash_cnt != 1) dash_cnt++;
            }
            res[cs++] = (cs <= 7 ? '*' : S[index]); 
        }
    }
    res[12] = '\0';
    
    return res;
}

int phoneSize(char* S, int size){
    int index, ps;
    ps = 0;
    
    for(index = 0;index < size;index++)
        if(isDigit(S[index]))
            ps++;
    
    return ps;
}

char* maskPII(char* S) {
    char* res;
    int new_size, name1_size;
    int size;
    int index;

    size = strlen(S);
    if(isEmail(S, size)){
        name1_size = nameSize(S, size);
        new_size = size - name1_size + 7;
        res = (char*)malloc(sizeof(char) * new_size);
        res[0] = toLowercase(S[0]);
        res[1] = res[2] = res[3] = res[4] = res[5] = '*';
        res[6] = toLowercase(S[name1_size - 1]);
        for(index = 6;index < new_size;index++){
            res[index] = toLowercase(S[name1_size - 1 + index - 6]);
        }
    }else{
        int ps = phoneSize(S, size);
        if(ps == 10){
            res = noCountryCode(S, size);
        }else if(ps == 12){
            res = countryCode(S, size);
        }else if(ps == 11){
            res = countryCode11(S, size);
        }else if(ps == 13){
            res = countryCode13(S, size);
        }
    }
    return res;
}