#include <limits>
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        // example of negative arithmetic: -27 % 10 = -7
        while (x != 0) {
            int digit = x % 10;

            if (result > std::numeric_limits<int>::max() / 10 ||
                result == std::numeric_limits<int>::max() / 10 && digit > std::numeric_limits<int>::max() % 10)
                    return 0;

            if (result < std::numeric_limits<int>::min() / 10 ||
                result == std::numeric_limits<int>::min() / 10 && digit < std::numeric_limits<int>::min() % 10)
                    return 0;

            result = 10 * result + digit;
            x /= 10;
        }
        return result;
    }
};
