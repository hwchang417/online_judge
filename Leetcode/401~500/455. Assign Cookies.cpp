class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int index, gsize, ssize, gptr, sptr;
        int cnt;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        gsize = g.size();
        ssize = s.size();
        cnt = gptr = sptr = 0;
        while(gptr < gsize && sptr < ssize){
            if(g[gptr] <= s[sptr]){
                gptr++;
                cnt++;
            }
            sptr++;
        }
        return cnt;
    }
};