class Solution {
public:
    
    //version 1
    string convertToTitle1(int n) {
        //轉26進制，用A~Z
        int m, index, borrow;
        m = n % 26;
        string res;
        vector<int> q;
        
        //convert to 26 進制
        while(n > 26){
            m = n % 26;
            n /= 26;
            q.push_back(m);
        }
        if(n != 0) q.push_back(n);
        
        //如果最後一位是0，則做減一的借位減法
        for(index = 0;index < q.size() - 1 && q[index] <= 0;index++){
            q[index] = 26;
            q[index + 1]--;
            cout << q[index] << endl;
        }
        if(q[q.size() - 1] == 0) q.pop_back();
        
        //convert number to excel title
        for(index = q.size() - 1;index >= 0;index--){
            res += char(q[index] + 'A' - 1);
        }
        
        return res;
    }
    
    //version 2
    //先對n - 1，再取其餘數
    //數字0對應到A
    //數字25對應到Z
    string convertToTitle(int n) {
        string dict("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        string res;
        
        while(n > 0){
            n -= 1;
            int remain = n % 26;
            n /= 26;
            res = dict[remain] + res;            
        }
        
        return res;
    }
};