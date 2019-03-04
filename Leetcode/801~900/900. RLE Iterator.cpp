class RLEIterator {
public:
    int pos;
    vector<int> num;
    
    RLEIterator(vector<int> A) {
        num = A;
        pos = 0;
    }
    
    int next(int n) {
        int cur, ret;
        if(pos >= num.size()) return -1;
        cur = num[pos];
        if(cur >= n){
            ret = num[pos + 1];
            num[pos] -= n;
        }else{
            pos += 2;
            ret = next(n - cur);
        }
        return ret;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */