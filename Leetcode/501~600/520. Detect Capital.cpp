class Solution {
public:
    bool detectCapitalUse(string word) {
        int index, len;
        if(word.size() == 1) return true;
        
        len = word.size();
        if(word[0] <= 'Z' && word[1] <= 'Z'){
            //case 1: all of characters need to be uppercase
            for(index = 2;index < len;index++)
                if(word[index] > 'Z') return false;
        }else if((word[0] <= 'Z' && word[1] >= 'a') ||
                 (word[0] >= 'a' && word[1] >= 'a')){
            //case 2: first character is uppercase and other is lowercase
            //case 3: all of characters are lowercase
            for(index = 2;index < len;index++)
                if(word[index] < 'a') return false;
        }else
            return false;
        return true;
    }
};