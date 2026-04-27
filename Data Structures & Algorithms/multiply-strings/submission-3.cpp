class Solution {
public:
    string multiply(string num1, string num2) {
        // Handle multiplication by 0
        if (num1 == "0" || num2 == "0") return "0";

        // Since num1 and num2 can be 200 digits long,
        // num1 < 10^l1, num2 < 10^l2, -> num1*num2 < 10^(l1+l2)
        std::vector<int> digits(num1.size() + num2.size(), 0);
        // Vector of zeros guaranteed to hold the digits,
        // where digits[i] is the digit for placevalue 10^i

        // Reverse the strings so we can iterate from least to most significant digits
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        // Let's process all the digits in num1 starting from the ones place (10^0)
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                // (num1[i] * 10^i) * (num2[j] * 10^j) = num1[i]*num2[j] * 10^(i+j)
                // Since the digit product num1[i]*num2[j] = 10A + B, we have:
                // (10A + B) * 10^(i+j) = A * 10^(i+j+1) + B * 10^(i + j)
                //
                // Add the product to the digit for 10^(i+j),
                // Then reinforce the invariant that digit is <= 9 (Put tens into next placevalue.)
                digits[i + j] += (num1[i] - '0') * (num2[j] -'0'); // Subtract ASCII char value '0' to convert to int
                digits[i + j + 1] += digits[i + j] / 10;
                digits[i + j] %= 10;
            }
        }

        // Advance index backwards to the first nonzero digit
        // This is the most significant digit.
        int k = digits.size()-1;
        while (digits[k] == 0) --k;
        // Now insert the digits into the stringstream to construct the digits string.
        std::stringstream ss;
        for (; k >= 0; --k) {
            ss << digits[k];
        }
        return ss.str();
    }
};
