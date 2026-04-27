class Solution {
public:
    // Brute force recursive approach (for practice)
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        // Use a helping function to answer the question:
        // "Can we jump to the last index starting from index START?""
        return canJump (nums, 0);
    }

private:
    // Can we jump from START to the last index in NUMS?
    bool canJump(const std::vector<int>& nums, int start) {
        // Base case:
        // We can get to the last index if we are already there.
        if (start == nums.size()-1)
            return true;
        // We can never get to the last index if we jumped past it.
        if (start >= nums.size())
            return false;

        // Recursively explore all the spaces we could reach
        // from here, and use them as the next starting position.
        // The possible jump lengths range from 1 to nums[start]
        for (int i = 1; i <= nums[start]; ++i) {
            if (canJump(nums, start + i))
                return true;
        }
        return false;
    }
};
