class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // In the binary reperesentation of n,
        // The ones place represents 2^0, the two's place is 2^1, ...
        // until the last place 2^31 (for a 32-bit unsigned int)
        //
        // To reverse the bits, the digit for 2^k in the original number,
        // becomes the digit for 2^(31-k) in the binary reversal.
        uint32_t result = 0;
        for (int i = 31; i >= 0; --i) {
            // Get the bit for 2^i in n
            uint32_t mask = 1 << i;
            if (n & mask) {
                result |= 1 << (31 - i);
            }
        }
        return result;
    }
};
