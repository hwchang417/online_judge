
int climbStairs(int n) {
    int i;
    int n_1 = 1;
    int n_2 = 2;
    int n_3 = n_1 + n_2;
    
    if(n == n_1) return n_1;
    if(n == n_2) return n_2;
    if(n == n_3) return n_3;
    
    for(i = 4;i <= n;i++){
    	n_1 = n_2;
    	n_2 = n_3;
    	n_3 = n_1 + n_2;
	}
    
    return n_3;
}