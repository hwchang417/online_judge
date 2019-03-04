class Solution {
public:
	int removeDuplicates(vector<int>& nums){
		
		int i, j, cnt, size;
		int prev;
		
		j = 0;
		size = nums.size();
		for(i = 0;i < size;i++){
			if(i && prev == nums[i]){
				if(cnt < 2)
					nums[j++] = nums[i];
				cnt++;
			}
			else{
				nums[j++] = nums[i];
				cnt = 1;
			}
			prev = nums[i];
		}

		return j;
	}

};