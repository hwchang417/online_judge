class Solution {
public:
    //amazing solution
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
    
    // Accepted but too slow
//     void rotate(vector<int>& nums, int k) {
//         int index;
//         vector<int>::iterator it;
        
//         for(index = 0;index < k;index++){
//             int tmp = nums.back();
            
//             it = nums.begin();
//             nums.insert ( it , tmp );
            
//             nums.pop_back();
//         }
        
//     }
    
    //Accepted but not space O(1)
//     void rotate(vector<int>& nums, int k) {
//         int size = nums.size();
//         int index;
//         vector<int> res;
        
//         k = k % size;
//         for(index = size - k;index < size;index++)
//             res.push_back(nums[index]);
        
//         for(index = 0;index < size - k;index++)
//             res.push_back(nums[index]);
        
//         nums = res;
//     }
    
    //TLE
//     void rotate(vector<int>& nums, int k) {
//         int times, index, size, num;
//         times = 0;
//         size = nums.size();
//         while(times < k){
//             //rotate one step
//             num = nums[size - 1];
//             for(index = size - 2;index >= 0;index--)
//                 nums[index + 1] = nums[index];
//             nums[0] = num;
//             times++;
//         }
//     }
};