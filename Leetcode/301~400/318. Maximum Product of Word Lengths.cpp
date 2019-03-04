class Solution {
public:
    
    
    int maxProduct(vector<string>& words) {
        
        int index1, index2, max, max_len, size;
        size = words.size();
        vector<int> dictionary(size, 0); //initialize with all zeroes.
        
        max_len = 0;
        
        //store words into dictionary
        for(index1 = 0;index1 < size;index1++){
            int table = 0, len = words[index1].size();
            string& str = words[index1];
            for(index2 = 0;index2 < len;index2++)
                table |= (1 << (str[index2] - 'a'));
            dictionary[index1] = table;
        }
        
        for(index1 = 0;index1 < size;index1++){
            int len1 = words[index1].size();
            for(index2 = index1 + 1;index2 < size;index2++){
                if((dictionary[index1] & dictionary[index2]) == 0){
                    int total_len = len1 * words[index2].size();
                    if(total_len > max_len) max_len = total_len;
                }
            }
        }
        
        return max_len;
    }
};