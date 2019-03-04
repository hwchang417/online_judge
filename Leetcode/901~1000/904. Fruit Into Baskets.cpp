#define NONE INT_MIN
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int index, size;
        int type1, type2, index2;
        int count, max_count;
        
        if(tree.size() <= 1) return tree.size();
        
        type1 = type2 = NONE;
        count = 0;
        max_count = 2;
        index = -1;
        size = tree.size();
        while(index < size - 1){
            index++;
            count++;
            
            if(type1 == tree[index] || type2 == tree[index]){
            }else if(type1 == NONE)
                type1 = tree[index];
            else if(type2 == NONE)
                type2 = tree[index], index2 = index;
            else
                index = index2, count = 1, type1 = type2, type2 = NONE;
            if(count > max_count) 
                max_count = count;
        }
        return count > max_count ? count : max_count;
    }
};