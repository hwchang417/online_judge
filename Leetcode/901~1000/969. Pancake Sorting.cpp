class Solution {
public:
    int findMax(vector<int> &A){
        int idx, max, max_index;
        max = A[0]; max_index = 0;
        for(idx = 1;idx < A.size();idx++)
            if(A[idx] > max) 
                max = A[idx], max_index = idx;
        return max_index;
    }
    
    void reverse(vector<int> &A, int l, int r){
        while(l < r){
            int tmp = A[l];
            A[l] = A[r];
            A[r] = tmp;
            l++, r--;
        }
    }
    
    vector<int> pancakeSort(vector<int>& A) {
        int idx, max, max_index;
        vector<int> res;
        
        while(A.size() > 1){
            max_index = findMax(A);
            if(max_index == A.size() - 1){
                A.pop_back();
                continue;
            }
            
            if(max_index == 0){
                reverse(A, max_index, A.size() - 1);
                res.push_back(A.size());
                continue;
            }
            
            reverse(A, 0, max_index);
            res.push_back(max_index + 1);
            
            reverse(A, 0, A.size() - 1);
            res.push_back(A.size());
            A.pop_back();
        }
        
        return res;
    }
};