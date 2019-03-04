class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int mod = 1000000007;
        int i, j, k;
        long long cnt;
        int c[101] = {0};
        for(int n : A) c[n]++;
        
        cnt = 0;
        for(i = 0;i <= 100;i++){
            for(j = i;j <= 100;j++){
                int k = target - i - j;
                if(i <= k && k <= 100)
                    if(i < j && j < k)
                        cnt += (long long)c[i] * c[j] * c[k];
                    else if(i == j && j < k)
                        cnt += (long long)c[i] * (c[i] - 1) * c[k] / 2;
                    else if(i < j && j == k)
                        cnt += (long long)c[i] * (c[j] - 1) * c[j] / 2;
                    else if(i == j && j == k)
                        cnt += (long long)c[i] * (c[i] - 1) * (c[i] - 2) / 6;
            }        
            
        }
        return (int)(cnt % mod);
    }
};