class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n, t, nsize, tsize;
        
        nsize = name.size();
        tsize = typed.size();
        for(t = 0, n = 0;typed[t] == name[n] && n < nsize - 1 && t < tsize - 1;n++){
            if(name[n + 1] != name[n])
                while(t < tsize - 1 && typed[t] == typed[t + 1]) t++;
            t++;
        }
        
        return typed[t] == name[n] && n == nsize - 1;
    }
};