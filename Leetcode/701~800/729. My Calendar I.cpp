
class MyCalendar {
public:
    vector<pair<int, int>> point;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        int index, size;
        
        size = point.size();
        for(pair<int, int> p : point)
            if((p.second > start && p.first < end) || (end > p.first && p.second > end))
                return false;
        
        //insert point into list
        for(index = 0;index < size;index++)
            if(point[index].second > end){
                point.insert(point.begin() + index, pair<int, int>(start, end));
                return true;
            }
        
        point.push_back(pair<int, int>(start, end));
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */