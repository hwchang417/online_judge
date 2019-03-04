class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res;
        if(B > A){
            while(A > 0 || B > 0){
                if(B > 0) res += 'b', B--;
                if(B > A) res += 'b', B--;
                if(A > 0) res += 'a', A--;
            }
        }else{
            while(A > 0 || B > 0){
                if(A > 0) res += 'a', A--;
                if(A > B) res += 'a', A--;
                if(B > 0) res += 'b', B--;
            }
        }
        return res;
    }
};