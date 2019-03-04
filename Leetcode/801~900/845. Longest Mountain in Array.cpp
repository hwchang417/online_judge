class Solution {
public:
    int longestMountain(vector<int>& A) {
        int index, prev;
        int size = A.size();
        int cnt, max;
        
        max = cnt = index = 0;
        while(index < size - 1){
            //up
            while(index < size - 1 && A[index] < A[index + 1]) index++, cnt++;
            
            if(cnt == 0){ index++; continue; }
            
            prev = index;
            //down
            while(index < size - 1 && A[index] > A[index + 1]) index++, cnt++;
            
            if(prev != index){
                if(cnt + 1 > max){
                    max = cnt + 1;
                }
            }
            cnt = 0;
        }
        
        return max;
    }
};