class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int optr, eptr, size;
        vector<int> res(A.begin(), A.end());
        
        eptr = 0;
        optr = 1;
        size = A.size();
        while(1){
            while(eptr < size && (res[eptr] & 0x01) == 0) eptr += 2;
            while(optr < size && (res[optr] & 0x01) != 0) optr += 2;
            
            if(eptr >= size || optr >= size) break;
            
            int tmp = res[eptr];
            res[eptr] = res[optr];
            res[optr] = tmp;
        }
        return res;        
    }
};