class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int max_point, point, sell, buy;
        
        sort(tokens.begin(), tokens.end());
        
        if(tokens.size() == 0 || P < tokens[0]) return 0;
        
        max_point = 1;
        point = buy = 0;
        sell = tokens.size() - 1;
        //先買再賣，看賣完的可以買多少power
        do{
            //先買到沒有
            while(P >= tokens[buy] && buy <= sell){
                P -= tokens[buy++];
                point++;
                max_point = max(max_point, point);
            }
            
            //再買
            if(point > 0){
                P += tokens[sell--];
                point--;
            }
            
        }while((P >= tokens[buy] && buy <= sell));
        
        return max_point;
    }
};