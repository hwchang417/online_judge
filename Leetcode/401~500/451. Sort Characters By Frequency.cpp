
typedef struct{
    char c;
    int cnt;
}Char;

class Solution {
public:
    
    static bool cmp(Char &a, Char &b){
        return a.cnt > b.cnt;
    }
    
    string frequencySort(string s) {
        int index, len, cnt, rptr;
        Char table[128];
        
        len = s.size();
        string res(len, ' ');
        
        //reset all of counts in table
        memset(table, 0, sizeof(Char) * 128);
        
        for(index = 0;index < 128;index++)
            table[index].c = index;
        
        //the number of 26 alphabet
        for(index = 0;index < len;index++)
            table[s[index]].cnt++;
        
        //sorting array with count
        sort(table, table + 128, cmp);
        
        rptr = 0;
        for(index = 0;index < 128 && table[index].cnt > 0;index++){
            for(cnt = 0;cnt < table[index].cnt;cnt++)
                res[rptr++] = table[index].c;
        }
        
        return res;
    }
};