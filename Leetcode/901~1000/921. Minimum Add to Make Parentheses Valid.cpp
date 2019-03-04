class Solution {
public:
    int minAddToMakeValid(string S) {
        int cnt, index, size;
        stack<char> s;
        
        cnt = 0; size = S.size();
        for(index = 0;index < size;index++){
            if(S[index] == '(')
                s.push(S[index]);
            else if(!s.empty() && s.top() == '(')
                s.pop();
            else
                cnt++;
        }
        
        return s.size() + cnt;
    }
};