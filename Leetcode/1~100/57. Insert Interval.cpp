/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int now;
        int size = intervals.size(); 
        Interval overlap;
        vector<Interval> res;
        overlap.start = newInterval.start;
        overlap.end = newInterval.end;
        for(now = 0;now < size;now++){
            if(intervals[now].end < overlap.start){
                //no overlap before
                res.push_back(intervals[now]);
            }else if(intervals[now].start > overlap.end){
                //no overlap after
                res.push_back(overlap);
                while(now < size)
                    res.push_back(intervals[now++]);
                return res;
            }else{
                overlap.start = min(intervals[now].start, overlap.start);
                overlap.end = max(intervals[now].end, overlap.end);
            }
        }
        res.push_back(overlap);
        return res;
    }
};