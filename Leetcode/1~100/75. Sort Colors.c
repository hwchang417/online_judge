
void sortColors(int* nums, int numsSize) {
	int i, j;
	int color[3] = {0};
	
	for(i = 0;i < numsSize;i++)
		color[nums[i]]++;
	
	for(i = j = 0;i < 3;i++)
		while(color[i]--)
			nums[j++] = i;
	
}
