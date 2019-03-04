class Solution {
public:
    bool checkPerfectNumber(int num){
        bool result = (num - 6 == 0) || (num - 28 == 0) || (num - 496 == 0) || (num - 8128 == 0) || (num - 33550336 == 0);
        return result;
    }
    
//     bool checkPerfectNumber(int num) {
//         int index, sum, to = (int)sqrt(num);
        
//         if(num == 1) return false;
        
//         sum = 1;
//         for(index = 2;index <= to;index++){
//             if(num % index == 0){ sum += (index + num / index); }
//         }
        
//         return num == sum;
//     }
};