class Solution {
public:
    bool isValid(string S) {
        int idx, count;
        char str[] = {'a', 'b', 'c'};
        
        if((S.size() % 3) != 0) return false;
        
        do{
            count = 0;
            for(idx = 0;idx < S.size() && count < 3;){
                if(str[count] == S[idx]){
                    count++;
                    S = S.erase(idx, 1);
                }else idx++;
            }
        }while(count == 3 && S.size() > 0);
        
        return 0 == S.size();
    }
};