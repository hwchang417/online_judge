class Solution {
public:
	int getSum(int a, int b) {
		int tmp;
		tmp = INT_MAX;
		
		while(tmp && b){
			tmp = a & b;
			a = a ^ b;
			b = tmp << 1;
		}

		return a;
	}
};
