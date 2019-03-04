
class TimeMap {
public:
    /** Initialize your data structure here. */
    map<string, map<int, string>> m;
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto iter = m[key].upper_bound(timestamp); //非遞增序列當中(也就是遞減)，第一個小於timestamp的數
        return iter == m[key].begin() ? "" : prev(iter)->second;
    }
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */