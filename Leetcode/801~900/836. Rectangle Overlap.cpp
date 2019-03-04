#define isInsideX(rec, px) (px > rec[0] && px < rec[2])
#define isInsideY(rec, py) (py > rec[1] && py < rec[3])

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        bool result;
        result = isInsideX(rec1, rec2[0]) && (isInsideY(rec2, rec1[1]) || isInsideY(rec2, rec1[3]));
        result |= isInsideX(rec1, rec2[2]) && (isInsideY(rec2, rec1[1]) || isInsideY(rec2, rec1[3]) || isInsideY(rec1, rec2[1]));
        result |= isInsideX(rec2, rec1[0]) && (isInsideY(rec1, rec2[1]) || isInsideY(rec1, rec2[3]));
        result |= isInsideX(rec2, rec1[2]) && (isInsideY(rec1, rec2[1]) || isInsideY(rec1, rec2[3]) || isInsideY(rec2, rec1[1]));
        
        return result;
    }
};