class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // First sort the array: O(n log n)
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result = {};
        // For every index i (index of the first value)
        // - O(n) iterations
        // - Each iteration takes O(n)
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate values
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // Given i, try to find j, k with nums[i] + nums[j] + nums[k] == 0
            // nums[j] + nums[k] == -nums[i]
            // We maintain the invariant that i < j < k
            int target = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                // Case 1: Solution found!
                if (nums[j] + nums[k] == target) {
                    std::vector<int> triplet = {nums[i], nums[j], nums[k]};
                    result.emplace_back(triplet);
                    // We don't want duplicate triplets, so advance j and k until the value is different
                    int val = nums[j];
                    while (nums[j] == val) {
                        j++;
                    }
                } 
                // Case 2: Sum too small
                // We could increase the sum by increasing j or k, but we already know
                // there are no solutions with k' > k. So, increase j.
                else if (nums[j] + nums[k] < target) {
                    // There are no solutions with j' < j or with j' == j,
                    // So there are no solutions with j' < j + 1. Advance j.
                    ++j;
                } 
                // Case 3: Sum too big
                // We could decrease the sum by decreasing j or k, but we already know
                // by the loop invariant, there are no solutions with j' < j
                else { // nums[j] + nums[k] > target
                    // No solutions with k' > k or with k' == k, so there are no solutions
                    // with k' > k - 1.
                    --k;
                }
            }
        }
        // Return all the triplets found
        return result;
    }
};
