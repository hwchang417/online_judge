class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max, count;
        max = count = 0;
        for(int n : nums){
            if(n == 1){ 
                if(max < count + 1) max = count + 1;
                count++;
            }
            else count = 0;
            
        }
        return max;
    }
};