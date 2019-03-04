class Solution {
public:
    string getPermutation(int n, int k) {
        int i;
        int* fact;
        vector<char> input(n);
        string result;

        fact = new int[n + 1];
        fact[0] = 1;
        for(i = 0;i < n;i++)
            input[i] = i + '1';

        for(i = 1;i <= n;i++)
            fact[i] = i * fact[i - 1];

        for(i = n;i > 0;i--)
            fact[i] /= i;
        k--;
        for(i = n;i > 0;i--){
            int pos = k / fact[i];
            char c = input[pos];

            input.erase(input.begin() + pos);
            result += c;
            k = k % fact[i];
        }

        return result;
    }
};