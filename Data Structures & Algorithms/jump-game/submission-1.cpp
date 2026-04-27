class Solution {
public:
    // Brute force recursive approach (for practice)
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        // Use a helping function to answer the question:
        // "Can we jump to the last index starting from index START?""
        return dfs (nums, 0);
    }

private:
    // Can we jump from START to the last index in NUMS?
    bool dfs(const std::vector<int>& nums, int i) {
        // Base case:
        // We can get to the last index if we are already there.
        if (i == nums.size()-1)
            return true;
        // We can never get to the last index if we jumped past it.
        if (i >= nums.size())
            return false;

        // Recursively explore all the spaces we could reach
        // from here, and use them as the next starting position.
        // The possible jump lengths range from 1 to nums[i]
        for (int j = 1; j <= nums[i]; ++j) {
            if (dfs(nums, j + i))
                return true;
        }
        return false;
    }
};
