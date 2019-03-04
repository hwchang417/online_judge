/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#define max(a, b) (a > b ? a : b)

class Solution {
public:
    int GCD(int num1, int num2){
        int temp = -1;
        if(num2 == 0) return num1;
        while(temp != 0){
            temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }
        return num1;
    }
    
    int maxPoints(vector<Point>& points) {
        int i, j, max_value, size, localmax, vertical, overlap, temp;
        map<pair<int, int>, int> m;
        map<pair<int, int>, int>::iterator it;
        
        size = points.size();
        if(size == 0) return size;
        
        max_value = 0;
        for(i = 0;i < size;i++){
            localmax = 0;
            overlap = 0;
            vertical = 0;
            for(j = i + 1;j < size;j++){
                if(points[i].x == points[j].x &&
                   points[i].y == points[j].y){
                    overlap++;
                    continue;
                }else if(points[i].x == points[j].x){
                    vertical++;
                }else{
                    int dx = points[i].x - points[j].x, 
                        dy = points[i].y - points[j].y;

                    int common = GCD(dx, dy);
                    dx /= common;
                    dy /= common;
                    
                    if((temp = ++m[pair<int, int>(dx, dy)]) > localmax)
                        localmax = temp;
                }
                localmax = max(localmax, vertical);
            }
            max_value = max(max_value, localmax + overlap);
            m.clear();
        }
        
        return max_value + 1;
    }
};