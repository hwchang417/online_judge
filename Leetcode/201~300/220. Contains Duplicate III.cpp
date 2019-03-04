typedef struct element{
    int index, number;
    element(int i, int n) : index(i), number(n) {}
}Element;

class Solution {
public:
    static bool compare(const Element& num1, const Element num2){
        return num1.number < num2.number;
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        long long int lt = (long long int)t;
        int size = nums.size();
        vector<Element> arr;
        
        for(int index = 0;index < size;index++)
            arr.push_back(Element(index, nums[index]));
        
        sort(arr.begin(), arr.end(), compare);
        
        for(int start = 0;start < size;start++)
            for(int neighbor = start + 1;
                neighbor < size && 
                abs((long long int)arr[start].number - (long long int)arr[neighbor].number) <= lt
                ;neighbor++)
                if(abs(arr[start].index - arr[neighbor].index) <= k)
                    return true;
        
        return false;
    }
};