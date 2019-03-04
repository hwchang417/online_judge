class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int count, pos;
        if(points.size() <= 1) return points.size();
        
        sort(points.begin(), points.end(), [](auto &left, auto &right) {
            return left.second < right.second;
        });
        
        count = 1;
        pos = points[0].second;
        for(pair<int, int> p : points){
            if(pos < p.first){
                count++;
                pos = p.second;
            }
        }
        
        return count;
    }
};