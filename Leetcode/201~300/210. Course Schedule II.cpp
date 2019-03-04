class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites){
        int nth, idx, s;
        vector<int> res;
        queue<int> q;
        //number of classes need to be finished first
        vector<int> ref(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(idx = 0;idx < prerequisites.size();idx++){
            adj[prerequisites[idx].second].push_back(prerequisites[idx].first);
            ref[prerequisites[idx].first]++;
        }
        
        for(s = 0;s < numCourses;s++) 
            if(ref[s] == 0)
                q.push(s);
        
        while(!q.empty()){
            s = q.front();
            q.pop();
            
            res.push_back(s);
            ref[s] = -1;
            
            for(int n : adj[s]){
                ref[n]--;
                if(ref[n] == 0) 
                    q.push(n);
            }
        }
        
        return res.size() != numCourses ? vector<int>() : res;
    }
};