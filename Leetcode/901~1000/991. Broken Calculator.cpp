class Solution {
public:
    int brokenCalc(int X, int Y) {
        int cnt = 0;
        while(X < Y){
            Y = (Y & 0x01) == 0 && Y > X ? (Y >> 1) : Y + 1;
            cnt++;
        }
        return cnt + X - Y;
    }
};