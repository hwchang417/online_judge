class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        //嘗試2到hand.size() >> 1
        //的group組合
        //看能不能組成group size = W, group
        int index, prev, group;
        int size = hand.size();
        
        if(size % W != 0) return false;
        
        sort(hand.begin(), hand.end());
        
        index = 0;
        while(index < hand.size()){
            group = 0;
            while(group < W && index < hand.size()){
                if(group == 0){
                    prev = hand[index];
                    hand.erase(hand.begin() + index);
                    group++;
                }
                else if(prev + 1 == hand[index]){
                    prev = hand[index];
                    hand.erase(hand.begin() + index);
                    group++;
                }
                else if(prev == hand[index]) index++;
                else return false;
                
                
            }
            //cout << hand.size() << endl;
            if(group != W) return false;
            index = 0;
        }
        
        return hand.size() == 0;
    }
};