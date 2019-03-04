class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int mid, left, right, index, size;
        size = arr.size();
        
        if(size < k) 
            return arr;
        
        if(arr[0] >= x)    
            return vector<int>(arr.begin(), arr.begin() + k);
        
        if(arr[size - 1] <= x)    
            return vector<int>(arr.end() - k, arr.end());
        
        for(mid = 0;mid < size && arr[mid] < x;mid++);
        
        if(mid == 0 || abs(arr[mid - 1] - x) > abs(arr[mid] - x))
            left = right = mid;
        else
            left = right = mid - 1;
        
        while(left > 0 && right < size - 1 && right - left + 1 < k){
            if(x - arr[left - 1] > arr[right + 1] - x)
                right++;
            else
                left--;
        }
        
        if(left == 0)    
            return vector<int>(arr.begin(), arr.begin() + k);
        
        if(right == size - 1)    
            return vector<int>(arr.end() - k, arr.end());
        
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};