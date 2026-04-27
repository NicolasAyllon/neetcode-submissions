class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // In the binary reperesentation of n,
        // The ones place represents 2^0, the two's place is 2^1, ...
        // until the last place 2^31 (for a 32-bit unsigned int)
        //
        // To reverse the bits, the digit for 2^k in the original number,
        // becomes the digit for 2^(31-k) in the binary reversal.
        uint32_t res = n;
        // To reverse all the bits, swap the left and right halves, and reverse those...
        // Swap left and right halves of the 32-bit number
        res = ((res >> 16) | (res << 16));
        // Swap left and right halves of each 16-bit region (8 bits each)
        res = ((res & 0xff00ff00) >> 8) | ((res & 0x00ff00ff) << 8);
        // Swap left and right halves of each 8-bit region (4 bits each)
        res = ((res & 0xf0f0f0f0) >> 4) | ((res & 0x0f0f0f0f) << 4);
        // Swap left and right halves of each 4-bit region (2 bits each)
        res = ((res & 0xcccccccc) >> 2) | ((res & 0x33333333) << 2);
        // Swap left and right halves of each 2 bit region (1 bit each)
        res = ((res & 0xaaaaaaaa) >> 1) | ((res & 0x55555555) << 1);
        return res;
    }
};
