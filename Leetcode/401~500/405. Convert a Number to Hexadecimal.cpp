class Solution {
public:
    
    char dec2hex(int num){
        return (num >= 10 ? num - 10 + 'a' : num + '0');
    }
    
    string toHex(int num) {
        const int size = sizeof(num) << 1;
        int cnt = 0;
        string res;
        char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        
        if(num == 0) return string("0");
        
        while(num != 0 && cnt++ < size){
            //res.push_back(dec2hex(num & 0x0F));
            res = table[num & 0x0F] + res;
            num = num >> 4;
        }
        
        //reverse(res.begin(), res.end());
        
        return res;
    }
};