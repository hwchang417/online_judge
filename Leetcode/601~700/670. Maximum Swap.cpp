class Solution {
public:
    
    int itoa(int n, int* str){
        int num;
        if(n == 0) str[0] = 0;
        
        num = 0;
        while(n != 0){
            str[num++] = n % 10;
            n /= 10;
        }
        return num;
    }
    
    int atoi(int* str, int digits){
        int res, pos;
        for(res = 0, pos = digits - 1;pos >= 0;pos--){
            res = (res << 3) + (res << 1);
            res += str[pos];
        }
        return res;
    }
    
    void swap(int* num1, int* num2){
        int tmp = *num1;
        *num1 = *num2;
        *num2 = tmp;
    }
    
    int maximumSwap(int num) {
        int index, from, to, digits, pos, max;
        int integer[9] = {0};
        
        digits = itoa(num, integer);
        
        //find nth maximum value in all characters
        for(from = 0;from < digits - 1;from++){
            pos = 0; max = integer[0];
            for(to = 1;to < digits - from;to++){
                if(max < integer[to]){
                    max = integer[to];
                    pos = to;
                }
            }
            if(max != integer[digits - from - 1]){
                swap(&integer[digits - from - 1], &integer[pos]);
                break;
            }
        }
        
        return atoi(integer, digits);
    }
};