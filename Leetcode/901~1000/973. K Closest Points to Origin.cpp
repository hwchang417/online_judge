#define foreach(idx, size) for(idx = 0;idx < size;idx++)
typedef struct point{
    int dis;
    vector<int> p;
}POINT;

class Solution {
public:
    
    static bool cmp(POINT &p1, POINT &p2){
        return p1.dis < p2.dis;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int idx, size = points.size();
        vector<vector<int>> res(K);
        vector<POINT> p(size);
        
        //calculate distance of points to original point
        foreach(idx, size){
            p[idx].p = points[idx];
            p[idx].dis = points[idx][0] * points[idx][0] + points[idx][1] * points[idx][1];
        }
        
        sort(p.begin(), p.end(), cmp);
        
        foreach(idx, K)
            res[idx] = p[idx].p;
        
        return res;
    }
};