class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int index, size;
        int sindex, tindex;
        char table1[256] = {0};
        char table2[256] = {0};
        
        size = s.size();
        for(index = 0;index < size;index++){
            sindex = s[index];
            tindex = t[index];
            if(table1[sindex] == 0 && table2[tindex] == 0){
                table1[sindex] = tindex;
                table2[tindex] = sindex;
            }else if(table1[sindex] != tindex || table2[tindex] != sindex){
                return false;
            }
        }
        
        return true;
    }
};