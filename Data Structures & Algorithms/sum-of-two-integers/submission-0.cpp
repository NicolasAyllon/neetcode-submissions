class Solution {
public:
    int getSum(int a, int b) {
        // Let b hold the amount that remains to add into a.
        while (b != 0) {
            int carry = (b & a) << 1; // Save the carry bits resulting from 1+1 additions.
            a = a ^ b; // Perform additions of bits that do not result in a carry: (0+0, 0+1, 1+0)
            b = carry; // Update 'b' to hold the carries that we still need to add to a.
        }
        return a;
    }
};
