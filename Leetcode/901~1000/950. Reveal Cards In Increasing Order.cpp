
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int idx;
        vector<int> res(deck.size());
        queue<int> q1, q2;
        sort(deck.begin(), deck.end());
        
        for(idx = 0;idx < deck.size();idx++)
            q1.push(idx);
        
        while(!q1.empty()){
            int top = q1.front();    q1.pop();
            int second = q1.front(); q1.pop();
            
            q1.push(second);
            q2.push(top);
        }
        
        idx = 0;
        while(!q2.empty()){
            res[q2.front()] = deck[idx++];
            q2.pop();
        }
        
        return res;
    }
};