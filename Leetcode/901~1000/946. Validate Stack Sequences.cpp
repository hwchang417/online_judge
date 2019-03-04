class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        int pop, push, next, top;
        stack<int> s, tmp;
        vector<int>::iterator it;
        
        pop = push = 0;
        while(push < pushed.size() || pop < popped.size()){
            if(!s.empty() && popped[pop] == s.top()){
                s.pop();
                pop++;
                continue;
            }
            
            if(push < pushed.size() && popped[pop] == pushed[push]){ 
                push++;
                pop++;
                continue;
            }

            it = find(pushed.begin() + push, pushed.end(), popped[pop++]);
            if(it == pushed.end())
                return false;
            
            while(push < pushed.size() && pushed[push] != *it)
                s.push(pushed[push++]);
            
            push++;
        }
        
        return true;
    }
};