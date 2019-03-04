class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int index, size, count, email;
        
        size = accounts.size();
        vector<vector<int>> equal(size);
        vector<bool> visited(size, false);
        stack<int> s;
        
        map<string, int> m;
        set<string> tmp_set;
        vector<vector<string>> res;
        
        for(index = 0;index < size;index++){
            for(email = 1;email < accounts[index].size();email++){
                string str = accounts[index][email];
                //index != m[str]: avoid duplicated email
                if(m.find(str) != m.end() && index != m[str])
                    equal[index].push_back(m[str]), equal[m[str]].push_back(index);
                else
                    m[str] = index;
            }
        }
        
        count = 0;
        for(index = 0;index < size;index++){
            if(!visited[index]){
                s.push(index);
                
                while(!s.empty()){
                    int from = s.top();
                    s.pop();
                    visited[from] = true;
                    
                    for(string str : accounts[from])
                        tmp_set.insert(str);
                    
                    for(int to : equal[from])
                        if(!visited[to]) s.push(to);
                }
                
                res.push_back(vector<string>());
                for(string str : tmp_set)
                    res[count].push_back(str);
                count++;
                tmp_set.clear();
            }
        }
        
        return res;
    }
};