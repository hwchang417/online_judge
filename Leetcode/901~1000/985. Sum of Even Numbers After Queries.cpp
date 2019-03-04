class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int idx, sum = 0;
        vector<int> ans;
        
        for(int num : A)
            if((num & 0x01) == 0) sum += num;
        
        for(vector<int> v : queries){
            int value = v[0], index = v[1], total = A[index] + value;
            
            if((A[index] & 0x01) == 0 && (total & 0x01) == 0){
                sum += value;
            }else if((A[index] & 0x01) == 0 && (total & 0x01) == 1){
                sum -= A[index];
            }else if((A[index] & 0x01) == 1 && (total & 0x01) == 0){
                sum += total;
            }
            A[index] = total;
            ans.push_back(sum);
        }
        
        return ans;
    }
};