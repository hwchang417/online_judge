class Solution {
public:
    void permutation(vector<string>& res, string& S, int start){
        if(start == S.size()){
            res.push_back(S);
            return;
        }
        
        if((S[start] <= 'Z' && S[start] >= 'A') || (S[start] <= 'z' && S[start] >= 'a')){
            int c = S[start] <= 'Z' ? S[start] - 'A' : S[start] - 'a';
            S[start] = c + 'a';
            permutation(res, S, start + 1);
            S[start] = c + 'A';
        }
        permutation(res, S, start + 1);
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        permutation(res, S, 0);
        return res;
    }
};