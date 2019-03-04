class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int i, j, num;
        int y_power, x_power;
        vector<int> res;
        map<int, bool> m;
        x_power = y_power = 1;
        
        if(x == 1 && y == 1 && bound >= 2){
            res.push_back(2);
            return res;
        }
        
        if(x == 1){
            while(x + y_power  < bound){
                res.push_back(y_power + x);
                y_power = y_power * y;
            }
            return res;
        }
        
        if(y == 1){
            while(x_power + y  < bound){
                res.push_back(x_power + y);
                x_power = x_power * x;
            }
            return res;
        }
        
        for(i = 0;;i++){
            y_power = 1;
            num = x_power + y_power;
            if(x_power > bound) break;
            for(j = 0;num <= bound;j++){
                y_power *= y;
                m[num] = true;
                num = x_power + y_power;
            }
            x_power *= x;
        }
        
        for(pair<int, bool> p : m) res.push_back(p.first);
        
        return res;
    }
};