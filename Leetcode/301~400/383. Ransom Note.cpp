class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int index, len;
        int cnt[26] = {0};
        
        len = magazine.size();
        for(index = 0;index < len;index++)
            cnt[magazine[index] - 'a']++;
        
        len = ransomNote.size();
        for(index = 0;index < len;index++)
            if(--cnt[ransomNote[index] - 'a'] < 0)
                return false;
        
        return true;
    }
};