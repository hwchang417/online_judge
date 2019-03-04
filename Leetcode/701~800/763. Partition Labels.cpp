class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len, count, size, index, s, e;
        int start[26], end[26];
        vector<int> res;
        
        size = S.size();
        if(size == 0) return res;
        
        memset(start, -1, sizeof(int) * 26);
        memset(end, -1, sizeof(int) * 26);
        
        //record start and end position
        for(index = 0;index < size;index++){
            int ptr = S[index] - 'a';
            if(start[ptr] == -1)
                start[ptr] = index;
            end[ptr] = index;
        }
        
        //find range of each partition 
        len = 1;
        for(index = 0;index < size;index++){
            int ptr = S[index] - 'a';
            
            if(len == 1)
                s = start[ptr], e = end[ptr];
            else if(e < end[ptr])
                e = end[ptr];
            
            if(index == e)
                res.push_back(len), len = 0;
            len++;
        }
        
        return res;
    }
};