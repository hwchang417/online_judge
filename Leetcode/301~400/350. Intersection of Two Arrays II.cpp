class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int index1, index2;
        int size1, size2;
        int prev;
        vector<int> res;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        size1 = nums1.size();
        size2 = nums2.size();
        index1 = index2 = 0;
        while(index1 < size1 && index2 < size2){
            if(nums1[index1] < nums2[index2])
                index1++;
            else if(nums1[index1] > nums2[index2])
                index2++;
            else{
                prev = nums1[index1];
                res.push_back(prev);
                index1++;
                index2++;
            }
        }
        
        return res;
    }
};