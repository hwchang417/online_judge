/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    Interval overlapped(Interval& A, Interval& B){
        Interval interval;
        if(A.start <= B.start && B.end <= A.end){
            interval = B;
        }else if(A.start >= B.start && B.end >= A.end){
            interval = A;
        }else if(A.end >= B.start && B.start >= A.start){
            interval = Interval(B.start, A.end);
        }else if(B.end >= A.start && A.start >= B.start){
            interval = Interval(A.start, B.end);
        }else{
            interval = Interval(-1, -1);
        }
        return interval;
    }
    
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int idxA, idxB;
        Interval o;
        vector<Interval> ret;
        
        idxA = idxB = 0;
        while(idxA < A.size() && idxB < B.size()){
            o = overlapped(A[idxA], B[idxB]);
            //no Intersections
            if(A[idxA].end <= B[idxB].end){
                idxA++;
            }else{
                idxB++;
            }
            
            if(o.start != -1)
                ret.push_back(o);
        }
        return ret;
    }
};