class Solution {
public:
    
    int countPrimes(int n) {
        int count, i, j;
        bool* table;
        
        table = (bool*) malloc(sizeof(bool) * (n + 1));
        memset(table, false, sizeof(bool) * (n + 1));
        count = 0;
        
        for(i = 2;i < n;i++){
            if(!table[i]){
                count++;
                for(j = i << 1;j < n;j += i)
                    table[j] = true;
            }
        }
        
        return count;
    }
};
