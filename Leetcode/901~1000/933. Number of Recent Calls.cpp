class RecentCounter {
public:
    vector<pair<int, int>> pairs;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int count = 0, start = t - 3000;
        for(pair<int, int> p : pairs)
            if(start > p.second)
                count++;
        
        pairs.erase(pairs.begin(), pairs.begin() + count);
        
        pairs.push_back(pair<int, int>(t - 3000, t));
        
        return pairs.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */