#define isSquare(a, b, c) ((a == b && a + b == c) || (a == c && a + c == b) || (c == b && c + b == a))
class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2){
        int dx = (p1[0] - p2[0]);
        int dy = (p1[1] - p2[1]);
        return dx * dx + dy * dy;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        int d12, d13, d14;
        int d23, d24;
        int d34;
        bool result;
        
        d12 = distance(p1, p2);
        d13 = distance(p1, p3);
        d14 = distance(p1, p4);
        
        if(d12 == 0 || d13 == 0 || d14 == 0) return false;
        
        d23 = distance(p2, p3);
        d24 = distance(p2, p4);
        d34 = distance(p3, p4);
        
        result = isSquare(d12, d13, d14) && isSquare(d12, d23, d24) && isSquare(d13, d23, d34) && isSquare(d14, d24, d34);
        return result;
    }
};