class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // First approach: BRUTE_FORCE
        const int n = nums.size();

        std::vector<int> result;
        result.reserve(n);

        // For each window, the indices are [i, i + k).
        // (For the last window, i + k = n, so i = n - k)
        for (int i = 0; i + k <= n; ++i) {
            // Calculate maximum
            int window_max = nums[i];
            for (int j = i; j < i + k; ++j) {
                window_max = std::max(nums[j], window_max);
            }
            result.emplace_back(window_max);
        }
        return result;
    }
};
