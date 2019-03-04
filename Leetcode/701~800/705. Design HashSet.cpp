class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    vector<int> data;
    MyHashSet() {
        
    }
        
    int search(int key){
        int right, left, mid;
        left = 0;
        right = data.size() - 1;
        while(left <= right){
            mid = (left + right) >> 1;
            if(data[mid] == key) return mid;
            else if(data[mid] < key) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    
    int searchInsert(int target) {
        int numsSize = data.size();
        
        if(numsSize == 0) return 0;
        if(data[0] >= target) return 0;
        if(data[numsSize - 1] < target) return numsSize;

        int start = 1, end = numsSize - 1, mid;

        while(start + 1 < end){
            mid = start + ((end - start) >> 1);
            if(data[mid] == target){
                return mid;
            }else if(data[mid] < target){
                start = mid + 1;
            }else if(data[mid] > target){
                end = mid - 1;
            }
        }

        if(data[start] >= target){
            return start;
        }else if(data[end] >= target){
            return end;
        }
        return end + 1;
    }
    
    void add(int key) {
        int index = search(key);
        //insert element into the new place
        if(index < 0){
            index = searchInsert(key);
            data.insert(data.begin() + index, key);
        }
    }
    
    void remove(int key) {
        int index = search(key);
        if(index >= 0)
            data.erase(data.begin() + index);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return search(key) >= 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */