class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		if (!K)return A;
		int t, carry = 0, i = A.size() - 1;
		while(K!=0 || carry){
			t = K % 10;
			t += carry;
			if (i >= 0) {
				t += A[i];
				carry = t>=10?1:0;
				t = carry ? t - 10 : t;
				A[i--] = t;
			}
			else {
				carry = t >= 10 ? 1: 0;
				t = carry ? t - 10 : t;
				A.emplace(A.begin(), t);
			}
			K /= 10;
		}
		return A;
	}
};