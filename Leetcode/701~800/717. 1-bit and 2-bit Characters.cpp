class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index, size, prev;
        
        size = bits.size();
        for(index = 0;index < size;)
            prev = index, index = index + (bits[index] + 1);
        
        return index - 2 != prev;
    }
};