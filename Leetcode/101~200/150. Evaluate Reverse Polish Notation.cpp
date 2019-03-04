class Solution {
public:
    
    bool isOperator(string& s){
        if(s.size() != 1) return false;
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    
    int evalRPN(vector<string>& tokens) {
        int index, size, numerator, denominator, result;
        stack<int> operand;
        
        size = tokens.size();
        for(index = 0;index < size;index++){
            //is operator
            if(tokens[index].size() == 1 && isOperator(tokens[index])){
                denominator = operand.top();
                operand.pop();
                numerator = operand.top();
                if(tokens[index] == "+")
                    result = numerator + denominator;
                else if(tokens[index] == "-")
                    result = numerator - denominator;
                else if(tokens[index] == "*")
                    result = numerator * denominator;
                else
                    result = numerator / denominator;
                
                operand.pop();
                
                operand.push(result);
            }else{
                operand.push(stoi(tokens[index]));
            }
        }
        
        return operand.top();
    }
};