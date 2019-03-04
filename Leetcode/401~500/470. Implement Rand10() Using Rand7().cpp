// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        static int sum = 0;
        sum += rand7();
        return (sum % 10) + 1;
    }
};