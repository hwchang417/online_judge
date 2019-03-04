class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five, ten, index, billSize;
        //$5 -> +1
        //$10 -> -1個$5,  +1個10
        //$20 -> -1個$10, 1個$5 再加一個$20
        
        five = ten = 0;
        billSize = bills.size();
        for(index = 0;index < billSize;index++){
            if(bills[index] == 5){
                five++;
            }else if(bills[index] == 10){
                if(five == 0)
                    return false;
                five--;
                ten++;
            }else{
                if(five >= 1 && ten >= 1)
                    five--, ten--;
                else if(five >= 3)
                    five -= 3;
                else 
                    return false;
            }
        }
        return true;
    }
};