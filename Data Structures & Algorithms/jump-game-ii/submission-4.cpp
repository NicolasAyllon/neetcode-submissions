class Solution {
public:
    // Solve the same problem with dynamic programming (top down, memoization)
    int jump(vector<int>& nums) {
        // Memoized values (as an array/vector). -1 means not yet computed
        std::vector<int> memo(nums.size(), -1);
        return dfs(nums, 0, memo);
    }

private:
    // Return the minimum number of jumps to go from index i to last index 
    // (pass size as n for simplicity)
    int dfs(std::vector<int>& nums, int i, std::vector<int>& memo) {
        // Base case: already computed
        if (memo[i] != -1) return memo[i];

        // Base case: already at last index
        if (i == nums.size()-1) return 0;

        // Recursive case:
        // Min jumps from i to end is:
        //      1 (to index i + j) plus min jumps from i + j to the end
        //      Minimized over possible jumps j = 1...nums[i]
        int min_jumps = std::numeric_limits<int>::max();
        for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j) {
            if (dfs(nums, i + j, memo) != std::numeric_limits<int>::max())
                min_jumps = std::min(1 + dfs(nums, i + j, memo), min_jumps);
        }
        // Memoize result and return it.
        memo[i] = min_jumps;
        return memo[i];
    }
};
