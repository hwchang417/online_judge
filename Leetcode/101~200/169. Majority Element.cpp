class Solution {
public:
    
    //1. 先做sort，再遍尋找出出現次數最多的element
    //2. 因為數字一定過半，所以更新完一定會是有過半的數保留下來
    //
    int majorityElement(vector<int>& nums) {
        int prev, count;
        int index;
        int size = nums.size();
        
        prev = nums[0];
        count = 1;
        for(index = 1;index < size;index++){
            if(prev == nums[index]){
                count++;
            }else{
                if(count == 0){
                    prev = nums[index];
                    count = 1;
                }else{
                    count--;
                }
            }
        }
        return prev;
    }
//     int majorityElement(vector<int>& nums) {
//         int index, same, prev;
//         int size = nums.size();
//         int size_2 = (size >> 1) + (size & 0x01);
//         sort(nums.begin(), nums.end());
        
        
//         if(size != 0 && size <= 2) return nums[0];
//         prev = nums[0]; same = 1;
        
//         for(index = 1;index < size && same < size_2;index++){
//             if(nums[index] == prev){
//                 same++;
//             }else{
//                 prev = nums[index];
//                 same = 1;
//             }
//         }
//         return prev;
//     }
};