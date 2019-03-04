
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //merge two array
    int i;
    int nums3Size = nums1Size + nums2Size;
    int nums3Size_2 = nums3Size >> 1;
    int *nums3 = (int*)malloc(sizeof(int) * (nums3Size));
    double result;
    int *p1, *p2, *p3;
    
    p1 = nums1;
    p2 = nums2;
    p3 = nums3;
    
    for(i = 0;p1 != nums1 + nums1Size && p2 != nums2 + nums2Size;i++){
        if(*p1 > *p2){
            *p3 = *p2;
            p2++;
        }else{
            *p3 = *p1;
            p1++;
        }
        p3++;
    }
    
    //memcpy
    if(p1 != nums1 + nums1Size){
        memcpy(p3, p1, sizeof(int) * (nums3Size - i));
        //for(;i < nums3Size;) nums3[i++] = nums1[p1++];
    }else{
        memcpy(p3, p2, sizeof(int) * (nums3Size - i));
        //for(;i < nums3Size;) nums3[i++] = nums2[p2++];
    }
    
    result = nums3Size & 0x01 ? nums3[nums3Size_2] : (double)(nums3[nums3Size_2] + nums3[nums3Size_2 - 1] ) / 2.0;
    free(nums3);
    return result;
}