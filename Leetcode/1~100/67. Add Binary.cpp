class Solution {
public:

    string addBinary(string a, string b){
        int i, j, op1, op2, sizea, sizeb, carry, sum;
        string c;

        sizea = a.size(); sizeb = b.size(); carry = 0;
        for(i = sizea - 1, j = sizeb - 1;i >= 0 || j >= 0;){
            if(i >= 0) op1 = a[i--] - '0';
            if(j >= 0) op2 = b[j--] - '0';
            
            sum = op1 ^ op2 ^ carry;
            
            c = char(sum + '0') + c;
            carry = carry & op1 | op1 & op2 | carry & op2;
            op1 = op2 = 0;
        }

        if(carry)
            c = '1' + c;

        return c;
    }
};