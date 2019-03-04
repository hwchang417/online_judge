typedef struct{
    int count;
    char c;
}Table;

static bool cmp(Table& t1, Table& t2){
    return t1.count > t2.count;
}

class Solution {
public:
    string reorganizeString(string S) {
        int size = S.size();
        int ptr, index, start;
        
        vector<Table> table(26, Table());
        string res;
        
        index = 0;
        //initialize count table
        for(Table& t : table){
            t.count = 0;
            t.c = index++ + 'a';
        }
        
        //statistics
        for(char c : S)
            table[c - 'a'].count++;
        
        //sort table vector with its count
        sort(table.begin(), table.end(), cmp);
        
        //if the maximum of count in the table is greater than size_2, then it is not possible
        if(table[0].count > ((size + 1) >> 1))
            return res;
        
        //place it into res vector
        ptr = 0; 
        res = string(size, ' ');
        for(start = 0;start < 2;start++){
            index = start;
            while(index < size){
                if(table[ptr].count == 0) ptr++;
                table[ptr].count--;
                res[index] = table[ptr].c;
                index += 2;
            }
        }
        
        return res;
    }
};