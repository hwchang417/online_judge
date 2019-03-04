class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int idx, ret, pos_one, size;
        
        ret = pos_one = 0; size = seats.size(); 
        for(idx = 0;idx < size;idx++){
            if(seats[idx] == 1){
                if(pos_one == 0) ret = max(ret, idx);
                else ret = max(ret, (idx - pos_one + 1) >> 1);
                pos_one = idx + 1;
            }
        }
        
        ret = max(ret, (size - pos_one));
        return ret;
    }
};