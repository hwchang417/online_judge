/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int cnt = 0;
        map<int, Employee*> m;
        queue<Employee*> q;

        for(Employee *e : employees)
            m[e->id] = e;
        
        q.push(m[id]);
        while(!q.empty()){       
            Employee* e = q.front();
            q.pop();
            if(e == NULL) continue;
            cnt += e->importance;
            for(int n : e->subordinates)
                q.push(m[n]);
        }
        return cnt;
    }
};