int mySqrt(int n){
	long long r = n;
    while (r*r > n)
        r = (r + n/r) / 2;
	return r;
}