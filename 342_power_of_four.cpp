//Given an integer n, return true if it is a power of four. Otherwise, return false.

//An integer n is a power of four, if there exists an integer x such that n == 4x.

//Example 1:
//Input: n = 16
//Output: true

//Example 2:
//Input: n = 5
//Output: false

//Example 3:
//Input: n = 1
//Output: true

 //Follow up: Could you solve it without loops/recursion?

#include <math.h>

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 0)
            return false;
            
        float a = log(n) / log(4);
      
        return ceil(a) == floor(a);
    }
};
