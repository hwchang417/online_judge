
#define min(num1, num2) (num1 > num2 ? num2 : num1)

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int idx, num, table[26] = {0}, tmpTable[26];
        map<char, int> m;
        vector<string> res;
        
        for(char c : A[0])
            table[c - 'a']++;
        
        for(idx = 1;idx < A.size();idx++){
            memset(tmpTable, 0, sizeof(tmpTable));
            for(char c : A[idx])
                tmpTable[c - 'a']++;
            
            for(num = 0;num < 26;num++)
                table[num] = min(table[num], tmpTable[num]);
        }
        
        for(num = 0;num < 26;num++)
            while(table[num]--) res.push_back(string(1, (num + 'a')));
        
        return res;
    }
};