
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int i, j, size;
        int area, min_area = INT_MAX;
        map<int, vector<int>> m;
        bool isExist;
        
        size = points.size();
        for(vector<int> p : points)
            m[p[0]].push_back(p[1]);
        
        for(vector<int> p1 : points)
            for(vector<int> p2 : points){
                if(p1[0] == p2[0] || p1[1] == p2[1]) continue;
                
                isExist = find (m[p1[0]].begin(), m[p1[0]].end(), p2[1]) != m[p1[0]].end()
                        && find (m[p2[0]].begin(), m[p2[0]].end(), p1[1]) != m[p2[0]].end();
                
                if(isExist){
                    area = abs(p1[0] - p2[0]) * abs(p1[1] - p2[1]);
                    if(area < min_area)
                        min_area = area;
                }
            }
        
//         for(i = 0;i < size;i++){
//             for(j = i + 1;j < size;j++){
//                 int p1x, p1y, p2x, p2y;
//                 p1x = points[i][0]; p1y = points[i][1];
//                 p2x = points[j][0]; p2y = points[j][1];
                
//                 it1 = find (m[p1x].begin(), m[p1x].end(), p2y);
//                 it2 = find (m[p2x].begin(), m[p2x].end(), p1y);
                
//                 if(it1 != m[p1x].end() && it2 != m[p2x].end()){
//                     area = abs(p1x - p2x) * abs(p1y - p2y);
//                     if(area < min_area) 
//                         min_area = area;
//                 }
//             }
//         }
        
        return min_area == INT_MAX ? 0 : min_area;
    }
};