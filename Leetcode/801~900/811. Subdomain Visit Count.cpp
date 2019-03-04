class Solution {
public:
    int toInt(string str){
        int num = 0, s = 0;
        while(str[s] != '\0'){
            num = (num << 3) + (num << 1);
            num += str[s++] - '0';
        }
        return num;
    }
    
    string toString(int num){
        string res;
        if(num == 0) return string("0");
        while(num != 0){
            res += (num % 10) + '0';
            num /= 10;
        }
        reverse(res);
        return res;
    }
    
    void reverse(string& str){
        int l = 0, r = str.size() - 1;
        while(l < r){
            char c = str[l];
            str[l++] = str[r];
            str[r--] = c;
        }
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int start;
        map<string, int> count;
        vector<string> res;
        
        for(string str : cpdomains){
            int number, len;
            start = 0; len = str.size();
            while(start < len && str[start] != ' ') start++;
            
            number = toInt(str.substr(0, start));
            
            //split '.'
            while(start < len){
                start++;
                string key = str.substr(start, len - start);
                count[key] = count.find(key) != count.end() ? count[key] + number : number;
                while(start < len && str[start] != '.') start++;
            }
        }
        
        for(pair<string, int> p : count)
            res.push_back(toString(p.second) + " " + p.first);
        
        return res;
    }
};