class Solution {
public:
    bool isVowel(char c){
        c |= (0x20);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string toLowercase(string str){
        int idx, len = str.size();
        for(idx = 0;idx < len;idx++)
            str[idx] |= (0x20);
        return str;
    }
    
    bool isVowelDifferent(string& str1, string& str2){
        int idx, len1 = str1.size();
        
        if(len1 != str2.size()) return false;
        
        for(idx = 0;idx < len1;idx++){
            if(str1[idx] != str2[idx] && 
               !(isVowel(str1[idx]) && isVowel(str2[idx]))){
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int idx, len, i, flag, wsize = wordlist.size();
        vector<string> res, l(wsize);
        map<string, int> lowercase, word;
        
        for(idx = wsize - 1;idx >= 0;idx--){
            l[idx] = toLowercase(wordlist[idx]); 
            lowercase[l[idx]] = idx;
            word[wordlist[idx]] = idx;
        }
        
        len = queries.size();
        for(idx = 0;idx < len;idx++){
            string empty, lstr;
            if(word.find(queries[idx]) != word.end()){
                //original version of queries[idx] were matched
                res.push_back(queries[idx]);
            }else if(lowercase.find(lstr = toLowercase(queries[idx])) != lowercase.end()){
                //lowercase version of queries[idx] were matched
                res.push_back(wordlist[lowercase[lstr]]);
            }else{
                //if lowercase version of wordlist[i] and queries[idx] were equal, return true.
                for(i = 0;i < wsize;i++)
                    if(isVowelDifferent(lstr, l[i])) break;
                if(i != wsize) res.push_back(wordlist[i]);
                else res.push_back(empty);
            }
        }
        return res;
    }
};