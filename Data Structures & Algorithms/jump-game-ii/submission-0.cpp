class Solution {
public:
    int jump(vector<int>& nums) {
        // Let's create an array of the same size as nums,
        // where jumps[i] represents the minimm number of jumps
        // required to reach the last index, n-1 (where nums.size() == n)
        const int n = nums.size();
        std::vector<int> jumps(n, std::numeric_limits<int>::max()); 
        // -1 is a sentinel value, meaning IMPOSSIBLE to reach last index from here


        // First observe that the number of jumps required to get to index n-1
        // if we START there is zero (we're already there).
        jumps[n-1] = 0;

        // We'll iterate from the last index, back to the first
        // filling in the minimum number of steps to reach index n-1
        // from index i.
        for (int i = n-1; i >= 0; --i) {
            // For all valid jumps 1...nums[i] and where the landing index i+j is in bounds
            for (int j = 1; j <= nums[i] && i + j < n; ++j) {
                // The min number of jumps required to reach the end will be one jump (length j)
                // PLUS the minimum jumps required to reach the end from where we land, at index i + j
                // which was previously recorded in the jumps array
                if (jumps[i + j] != std::numeric_limits<int>::max())
                    jumps[i] = std::min(1 + jumps[i + j], jumps[i]);
            }
        }
        return jumps[0];
    }
};
