#include <limits>
class Solution {
public:
    int reverse(int x) {
        // return -16 % 10;
        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            // Appending next digit to result would exceed max value of int
            // 10*res + digit > INT_MAX
            if (res > 0 && res > (INT_MAX - digit)/10) return 0;
            if (res < 0 && res < (INT_MIN - digit)/10) return 0;
            // Appending next digit to result would go below min value of int
            // if (res < (INT_MIN - digit)/10) return 0;

            res = 10 * res + digit;
            x /= 10;
            std::cout << res << std::endl;
        }
        return res;
    }
};
