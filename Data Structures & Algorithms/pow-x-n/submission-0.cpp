class Solution {
public:
    double myPow(double x, int n) {
        // If n is negative (x = -k) 
        // return x^-k = 1/x^k = 1/(x^-(-k)) = 1/x^-n
        if (n < 0) return 1.0 / myPow(x, -n);
        // Base Cases: n = 0 and n = 1
        if (n == 0) return 1.0;
        if (n == 1) return x;

        // Recursive Case: n > 1
        // Divide into separate even and odd cases:
        // Even: n = 2k, so x^n = x^2k = (x^k)^2
        double y = myPow(x, n/2);
        return n % 2 == 0 ? y*y : y*y*x;
        // Odd: n = 2k + 1, so x^n = x^(2k+1) = x * (x^k)^2
    }
};
