class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        char Jtable[58] = {0};
        
        for(char c : J)
            Jtable[c - 'A']++;
        
        for(char s : S)
            count += Jtable[s - 'A'];
        
        return count;
    }
};