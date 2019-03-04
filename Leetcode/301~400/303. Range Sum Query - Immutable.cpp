class NumArray {
public:
    vector<int> integral;
    NumArray(vector<int> nums) {
        int index, size;
        size = nums.size();
        
        if(size == 0) return;
        
        integral.push_back(nums[0]);
        for(index = 1;index < size;index++)
            integral.push_back(integral[index - 1] + nums[index]);
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return integral[j];
        return integral[j] - integral[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */