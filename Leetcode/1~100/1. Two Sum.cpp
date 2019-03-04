
typedef struct twoInt{
    int key, value;
    twoInt(int k, int v) : key(k), value(v){}
}TwoInt;

class Solution {
public:
    
    static int sort_index_lcomparator(const TwoInt& a, const TwoInt& b) {
        return a.value < b.value;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int first, second, size, index;
        vector<int> res;
        
        vector<TwoInt> arr;
        
        size = nums.size();
        for(index = 0;index < size;index++)
            arr.push_back(TwoInt(index, nums[index]));
        
        sort(arr.begin(), arr.end(), sort_index_lcomparator);
        
        for(first = 0;first < size;first++){
            for(second = first + 1;second < size;second++){
                if(arr[first].value + arr[second].value == target){
                    res.push_back(arr[first].key);
                    res.push_back(arr[second].key);
                    return res;
                }else if(arr[first].value + arr[second].value > target){
                    break;
                }
            }
            
        }
        
        return res;
    }
};