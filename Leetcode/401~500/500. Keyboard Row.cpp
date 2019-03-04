class Solution {
public:
    
    vector<string> findWords(vector<string>& words) {
        int index, len, num, at, row;
        char table[127] = {0};
        vector<string> res;
        
        table['q'] = 1;        table['w'] = 1;
        table['e'] = 1;        table['r'] = 1;
        table['t'] = 1;        table['y'] = 1;
        table['u'] = 1;        table['i'] = 1;
        table['o'] = 1;        table['p'] = 1;
        
        table['a'] = 2;        table['s'] = 2;
        table['d'] = 2;        table['f'] = 2;
        table['g'] = 2;        table['h'] = 2;
        table['j'] = 2;        table['k'] = 2;
        table['l'] = 2;
        
        table['z'] = 3;        table['x'] = 3;
        table['c'] = 3;        table['v'] = 3;
        table['b'] = 3;        table['n'] = 3;
        table['m'] = 3;
        
        table['Q'] = 1;        table['W'] = 1;
        table['E'] = 1;        table['R'] = 1;
        table['T'] = 1;        table['Y'] = 1;
        table['U'] = 1;        table['I'] = 1;
        table['O'] = 1;        table['P'] = 1;
        
        table['A'] = 2;        table['S'] = 2;
        table['D'] = 2;        table['F'] = 2;
        table['G'] = 2;        table['H'] = 2;
        table['J'] = 2;        table['K'] = 2;
        table['L'] = 2;
        
        table['Z'] = 3;        table['X'] = 3;
        table['C'] = 3;        table['V'] = 3;
        table['B'] = 3;        table['N'] = 3;
        table['M'] = 3;        
        
        num = words.size();
        for(index = 0;index < num;index++){
            len = words[index].size();
            row = table[words[index][0]];
            
            for(at = 1;at < len && table[words[index][at]] == row;at++);
            
            if(at == len) res.push_back(words[index]);
        }
        
        return res;
    }
};