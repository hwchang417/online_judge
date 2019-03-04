class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        int nth, i;
        vector<int> res;
        if(N == 1){
            for(i = 0;i < 10;i++)
                res.push_back(i);
            return res;
        }
        
        if(K >= 6){
            for(i = 1;i < 10 - K;i++)
                res.push_back(i);
            for(i = K;i < 10;i++)
                res.push_back(i);
        }else if(K <= 5){
            for(i = 1;i < 10;i++)
                res.push_back(i);
        }
        
        for(nth = 1;nth < N;nth++){
            int size = res.size();
            for(i = 0;i < size;i++){
                int digit = res[i] % 10;
                int newDigit = (res[i] << 3) + (res[i] << 1);
                int sum = digit + K, minus = digit - K;

                if(sum == minus)
                    res[i] = newDigit + sum;
                else if(sum < 10 && minus >= 0) 
                    res[i] = newDigit + sum, res.push_back(newDigit + minus);
                else if(sum < 10){
                    res[i] = newDigit + sum;
                }else if(minus >= 0){
                    res[i] = newDigit + minus;
                }
            }
        }
        return res;
    }
};