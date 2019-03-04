class Solution {
public:
	bool dfs(int n, int begin, float sum, vector<int>& A){
		int i;
		if(n == 0)
			return sum == 0;
		
		for(i = begin;i < A.size() && sum >= A[i] * n;i++) //pruning
			if(dfs(n - 1, i + 1, (sum - A[i]), A))
				return true;
		
		return false;
	}

	bool splitArraySameAverage(vector<int>& A) {
		int i, sum, n;
		bool result;
		
		sum = 0; n = A.size();
		for(i = 0;i < n;i++)
			sum += A[i];
		
		sort(A.begin(), A.end());
		
		for(i = 1;i <= (n >> 1);i++){
			if(i * sum % n == 0 && dfs(i, 0, (float)i * sum / n, A)) //pruning
				return true;
		}
		
		return false;
	}
};