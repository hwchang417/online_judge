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

    static bool myfunction (Interval i,Interval j) { return (i.start < j.start); }
    vector<Interval> merge(vector<Interval>& intervals) {
        int i, j, size;
        vector<Interval> result;
        size = intervals.size();
        int* start = new int[size];
        int* end = new int[size];

        for(i = 0;i < size;i++){
            Interval interval = intervals[i];
            start[i] = interval.start;
            end[i] = interval.end;
        }
	
        sort(start, start + size);
        sort(end, end + size);
        j = 0;
        for(i = 0;i < size;i++){
            if(i == size - 1 || start[i+1] > end[i]){
                result.push_back(Interval(start[j], end[i]));
                j = i + 1;
            }
        }

        return result;
    }



};