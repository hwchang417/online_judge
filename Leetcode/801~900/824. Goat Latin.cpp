class Solution {
public:
    string toGoatLatin(string S) {
        bool isVowel[26] = {false};
        istringstream iss(S);
        string res, worda(1, 'a'), w;
        
        isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
        
        while(iss >> w){
            res += ' ' + (isVowel[(w[0] | 0x20) - 'a'] ? w : w.substr(1) + w[0]) + "ma" + worda;
            worda += 'a';
        }
        return res.substr(1);
    }
};