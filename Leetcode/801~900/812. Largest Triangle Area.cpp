class Solution {
public:
    
    double d(vector<int>& a, vector<int>& b){
        int d1 = a[0] - b[0], d2 = a[1] - b[1];
        return sqrt((double)(d1 * d1 + d2 * d2));
    }
    
    double harlong(double a, double b, double c){
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int i, j, k;
        double max = 0;
        int size = points.size();
        
        for(i = 0;i < size;i++){
            for(j = i + 1;j < size;j++){
                for(k = j + 1;k < size;k++){
                    //if(i == j || j == k || i == k) continue;
                    double l1 = d(points[i], points[j]), l2 = d(points[j], points[k]), l3 = d(points[k], points[i]);
                    double area = harlong(l1, l2, l3);
                    if(max < area)
                        max = area;
                }
            }
        }
        
        return max;
    }
};