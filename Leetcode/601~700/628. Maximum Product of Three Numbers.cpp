class Solution {
public:
    
    int maximumProduct(vector<int>& nums) {
        int i, j;
        int max1, max2, max3, min1, min2, size;
        
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        size = nums.size();
        for(i = 0;i < size;i++){
            int n = nums[i];
            if(n > max1){
                max3 = max2;
                max2 = max1;
                max1 = n;
            }else if(n > max2){
                max3 = max2;
                max2 = n;
            }else if(n > max3){
                max3 = n;
            }
            
            if(min1 > n){
                min2 = min1;
                min1 = n;
            }else if(min2 > n){
                min2 = n;
            }
        }
        
        max3 = max1 * max2 * max3;
        max2 = max1 * min1 * min2;
        return max3 > max2 ? max3 : max2;
    }
//     int maximumProduct(vector<int>& nums) {
//         int i, j;
//         int max1, max2, size;
        
//         size = nums.size();
//         for(i = 0;i < 3;i++){
//             for(j = 0;j < size - i - 1;j++){
//                 if(nums[j] > nums[j + 1]){
//                     int tmp = nums[j];
//                     nums[j] = nums[j + 1];
//                     nums[j + 1] = tmp;
//                 }
//             }
//         }
        
//         for(i = 0;i < 2;i++){
//             for(j = size - 4;j > i;j--){
//                 if(nums[j] < nums[j - 1]){
//                     int tmp = nums[j];
//                     nums[j] = nums[j - 1];
//                     nums[j - 1] = tmp;
//                 }
//             }
//         }
//         max1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
//         max2 = nums[0] * nums[1] * nums[size - 1];
//         return max1 > max2 ? max1 : max2;
//     }
    // int maximumProduct(vector<int>& nums) {
    //     int max1, max2, size;
    //     sort(nums.begin(), nums.end());
    //     size = nums.size();
    //     max1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
    //     max2 = nums[0] * nums[1] * nums[size - 1];
    //     return max1 > max2 ? max1 : max2;
    // }
};