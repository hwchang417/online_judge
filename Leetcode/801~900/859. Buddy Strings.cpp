class Solution {
public:
    
    
    bool buddyStrings(string A, string B) {
        int count[26] = {0};
        int index, diff;
        int lenA, lenB;
        
        lenA = A.size();
        lenB = B.size();
        
        if(lenA != lenB){
            return false;
        }
        diff = 0;
        for(index = 0;index < lenA;index++){
            if(A[index] != B[index]){
                diff++;
                if(diff >= 3) return false;
            }else{
                count[A[index] - 'a']++;
            }
        }
        
        for(index = 0;index < 26;index++){
            if(count[index] >= 2) return true;
        }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        return A == B && diff == 2;
    }
};