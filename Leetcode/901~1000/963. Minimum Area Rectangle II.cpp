
#define distance(x1, y1, x2, y2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#include <climit>

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int a, b, c, d; double w, l;
        double min_area = std::numeric_limits<double>::max(), area;
        map<pair<int, int>, bool> m;
        
        for(vector<int> p : points)
            m[make_pair(p[0], p[1])] = true;
        
        for(a = 0;a < points.size() - 2;a++){
            for(b = a + 1;b < points.size() - 1;b++){
                for(c = b + 1;c < points.size();c++){
                    int x1, y1, x2, y2, x3, y3, x4, y4;
                    x1 = points[a][0]; y1 = points[a][1];
                    x2 = points[b][0]; y2 = points[b][1];
                    x3 = points[c][0]; y3 = points[c][1];
                    x4 = x2 + x3 - x1; y4 = y2 + y3 - y1;
                    
                    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) != 0) continue;
                    if(m.find(make_pair(x4, y4)) == m.end()) continue;
                    w = distance(x4, y4, x2, y2);
                    l = distance(x4, y4, x3, y3);
                    area = w * l;
                    if(min_area > area)
                        min_area = area;
                }
            }
        }
        return min_area == std::numeric_limits<double>::max() ? 0.0 : min_area;
    }
};