
typedef struct element{
    int index, number;
    element(int i, int n) : index(i), number(n) {}
}Element;

class Solution {
public:
    //method1: compare with next k elements, O(n * k)
    //method2: make a structure that contains number and index, and then sorting array. 
    //         check whether a consecutive elements are the same or not?
    
    static bool compare(const Element& num1, const Element num2){
        return num1.number < num2.number;
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<Element> arr;
        
        for(int index = 0;index < size;index++)
            arr.push_back(Element(index, nums[index]));
        
        sort(arr.begin(), arr.end(), compare);
        
        for(int index = 1;index < size;index++)
            if(arr[index - 1].number == arr[index].number && abs(arr[index - 1].index - arr[index].index) <= k)
                return true;
        
        return false;
    }
};