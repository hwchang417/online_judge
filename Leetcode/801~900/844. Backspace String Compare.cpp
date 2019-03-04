class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int indexS, indexT;
        int sizeS, sizeT;
        
        indexS = indexT = 0;
        sizeS = S.size();
        sizeT = T.size();
        while(indexS < sizeS){
            if(S[indexS] == '#'){
                S.erase(S.begin() + indexS), sizeS--;
                if(indexS >= 1)
                    S.erase(S.begin() + indexS - 1), sizeS--;
                indexS = indexS <= 2 ? 0 : indexS - 2;
                
            }else{
                indexS++;
            }
        }
        cout << S << endl;
        while(indexT < sizeT){
            if(T[indexT] == '#'){
                T.erase(T.begin() + indexT), sizeT--;
                if(indexT >= 1)
                    T.erase(T.begin() + indexT - 1), sizeT--;
                indexT = indexT <= 2 ? 0 : indexT - 2;
            }else{
                indexT++;
            }
        }
        cout << T << endl;
        return S == T;
    }
};