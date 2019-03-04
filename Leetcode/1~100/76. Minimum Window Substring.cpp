class Solution {
public:
    string minWindow(string s, string t) {
        int idx, end, start, min_len, min_idx, tsize, ssize, count;
        int table[256] = {0};
        bool exist[256] = {0};
        
        ssize = s.size(); tsize = t.size();
        if(ssize == 0 || tsize == 0) return "";
        
        for(idx = 0;idx < tsize;idx++)
            table[t[idx]]++, exist[t[idx]] = true;
            
        end = -1; start = 0;
        min_idx = 0;
        min_len = INT_MAX;
        count = tsize;
        while(end < ssize && start < ssize){
            if(count){
                end++;
                table[s[end]]--;
                if(exist[s[end]] && table[s[end]] >= 0)
                    count--;
            }else{
                if(min_len > end - start + 1)
                    min_len = end - start + 1, min_idx = start;
                
                table[s[start]]++;
                if(exist[s[start]] && table[s[start]] > 0)
                    count++;
                start++;
            }
        }
        
        if(min_len == INT_MAX) return "";
        
        return s.substr(min_idx, min_len);
    }
};