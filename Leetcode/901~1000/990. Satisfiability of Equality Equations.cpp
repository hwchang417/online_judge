
class Solution {
public:
    int group[26];
    bool equationsPossible(vector<string>& equations) {
        int i, size = equations.size();
        
        for(i = 0;i < 26;i++) group[i] = i;
        
        for(string e : equations)
            if(e[1] == '=')
                group[find(e[0] - 'a')] = find(e[3] - 'a');
        
        for(string e : equations)
            if(e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        
        return true;
    }
    
    int find(int x){
        if(x != group[x]) group[x] = find(group[x]);
        return group[x];
    }
};