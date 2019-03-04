
void merge(int* nums1, int m, int* nums2, int n) {
    int i, j, k, size;
    
    if(nums1 == NULL || nums2 == NULL) return;
    
    j = k = 0;
    size = m + n;
    m--; n--;
    for(i = size - 1;m >= 0 && n >= 0;i--){
    	if(nums1[m] > nums2[n])
    		nums1[i] = nums1[m--];
   		else
   			nums1[i] = nums2[n--];
	}
    
    while(n >= 0)
    	nums1[i--] = nums2[n--];
    
}