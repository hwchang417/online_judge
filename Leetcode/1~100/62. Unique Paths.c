
#define min(a, b) (a > b? b : a)

int uniquePaths(int m, int n) {
    int i;
    int total = m + n - 2;
    int down = min(n - 1, m - 1);
    double res = 1.0;
    while(down){
    	res *= total;
    	res /= down;
    	total--;
    	down--;
	}
    return (int)(res + 0.5f);
}
