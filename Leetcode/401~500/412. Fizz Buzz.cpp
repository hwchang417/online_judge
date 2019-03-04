class Solution {
public:
    
    vector<string> fizzBuzz(int n) {
        int index, three, five, tf;
        vector<string> res;
        
        for(index = 1;index <= n;index++)
            res.push_back(to_string(index));
        
        for(three = 3;three <= n;three += 3)
            res[three - 1] = "Fizz";
        
        for(five = 5;five <= n;five += 5)
            res[five - 1] = "Buzz";
        
        for(tf = 15;tf <= n;tf += 15)
            res[tf - 1] = "FizzBuzz";
        
        return res;
    }
};