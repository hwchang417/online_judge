typedef struct{
    int time;
    int leading;
}Vote;

class TopVotedCandidate {
public:
    vector<Vote> box;
    int findMax(map<int, int>& in){
        int max_val, max_index, max_cnt;
        map<int, int>::iterator iter;
        
        max_cnt = max_val = -1;
        for(iter = in.begin();iter != in.end();iter++){
            int cnt = iter->second & 0xFFFF0000;
            int val = iter->second & 0x0000FFFF;
            if(val > max_val || (val == max_val && cnt > max_cnt)){
                max_cnt = cnt;
                max_val = val;
                max_index = iter->first;
            }
        }
        return max_index;
    }
    
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int index;
        Vote v;
        map<int, int> m;
        
        index = 0;
        for(int p : persons){
            if(m.find(p) != m.end())
                m[p]++;
            else
                m[p] = 1;
            m[p] = (m[p] & 0x0000FFFF) | (index << 16);
            v.time = times[index];
            v.leading = findMax(m);
            
            box.push_back(v);
            index++;
        }
    }
    
    int q(int t) {
        int leading;
        for(Vote v : box){
            if(t < v.time)
                break;
            leading = v.leading;
        }
        return leading;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */