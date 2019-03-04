class Solution {
public:
    
    void removeDots(string& emails){
        int index, size;
        size = emails.size();
        for(index = 0;index < size && emails[index] != '@';index++)
            if(emails[index] == '.')
                emails.erase(index, 1), index--;
    }
    
    void ignorePlus(string& emails){
        int index, size, start;
        
        index = 0; size = emails.size();
        
        while(index < size && (emails[index] != '@' && emails[index] != '+')) index++;
        
        start = index;
        if(emails[index++] == '@') return;
        
        while(emails[index] != '@') index++;
        
        emails.erase(start, index - start);
    }
    
    int numUniqueEmails(vector<string>& emails) {
        int index, size;
        map<string, bool> m;
        
        size = emails.size();
        for(index = 0;index < size;index++){
            ignorePlus(emails[index]);
            removeDots(emails[index]);
            m[emails[index]] = true;
        }
        
        return m.size();
    }
};