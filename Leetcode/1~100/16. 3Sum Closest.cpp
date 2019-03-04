#include <algorithm>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest, size, original_i, original_ij, abs_o, abs_c, prev, next;
        
        if((size = nums.size()) < 3) return -1;
        
        sort(nums.begin(), nums.end());
        
        closest = nums[0] + nums[1] + nums[2];
        abs_c = target - closest;
        abs_c = abs_c >= 0 ? abs_c : -abs_c;
        
        for(int i = 0;i < size;i++){
            original_i = nums[i];
            for(int j = i + 1;j < size;j++){
                prev = next = 0;
                original_ij = original_i + nums[j];
                for(int z = j + 1;z < size;z++){
                    
                    abs_o = target - (original_ij + nums[z]);
                    abs_o = abs_o >= 0 ? abs_o : -abs_o;
                    if(abs_o < abs_c){
                        abs_c = abs_o;
                        closest = (original_ij + nums[z]);
                    }
                    //當誤差是遞增時，跳出搜尋
                    if(prev < next && next > abs_c) break;
                    prev = next;
                    next = abs_o;
                }
            }
        }
        
        return closest;
    }
};