/**
 * Taking 1~n as root respectively:
 *      1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
 *      2 as root: # of trees = F(1) * F(n-2) 
 *      3 as root: # of trees = F(2) * F(n-3)
 *      ...
 *      n-1 as root: # of trees = F(n-2) * F(1)
 *      n as root:   # of trees = F(n-1) * F(0)
 *
 * So, the formulation is:
 *      F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)
 */

int numTrees(int n) {
    int i, j, res;
    int* F; 
    if(n == 0 || n == 1) return 1;
    F = (int*)calloc(n + 1, sizeof(int)); 
    F[0] = F[1] = 1;
    for(i = 2;i <= n;i++){
        for(j = 1;j <= i;j++){
            F[i] += F[j - 1] * F[i - j];
        }
    }
    res = F[n];
    free(F);
    return res; 
}