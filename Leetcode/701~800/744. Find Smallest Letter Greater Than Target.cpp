class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target >= letters[letters.size() - 1]) return letters[0];
        
        //找大於但最近的element，且呈現circular的關係
        for(char c : letters)
            if((c > target))
                return c;
        
        return target;
    }
};