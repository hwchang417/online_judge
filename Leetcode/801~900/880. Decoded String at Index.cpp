class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int idx;
        string res;
        long long int N;
        
        //先取N到超過K
        for(N = 0, idx = 0;N < K;idx++)
            N = (isdigit(S[idx])) ? N * (S[idx] - '0') : N + 1;
        
        //如果是數字，則除以該數字
        //如果取N的餘數為零，則回傳該字串
        while(idx--){
            if(isdigit(S[idx])) N /= S[idx] - '0', K %= N;
            else if(K % N-- == 0) return string(1, S[idx]);
        }
        
        return res;
    }
};