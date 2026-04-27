class Solution {
public:
    // Solve the same problem with dynamic programming (top down, memoization)
    int jump(vector<int>& nums) {
        const int n = nums.size();
        // Memoized values (as an array/vector). -1 means not yet computed
        std::vector<int> memo(n, -1);
        memo[n-1] = 0;
        return dfs(nums, memo, 0, n);
    }

private:
    // Return the minimum number of jumps to go from index i to last index 
    // (pass size as n for simplicity)
    int dfs(std::vector<int>& nums, std::vector<int>& memo, int i, int n) {
        // Base case: already computed
        if (memo[i] != -1) return memo[i];

        // Base case: already at last index
        if (i == n-1) return 0;

        // Recursive case:
        // Find min jumps
        int min_jumps = std::numeric_limits<int>::max();
        for (int j = 1; j <= nums[i] && i + j < n; ++j) {
            if (dfs(nums, memo, i + j, n) != std::numeric_limits<int>::max())
                min_jumps = std::min(1 + dfs(nums, memo, i + j, n), min_jumps);
        }
        // Memoize result and return it.
        memo[i] = min_jumps;
        return memo[i];
    }
};
