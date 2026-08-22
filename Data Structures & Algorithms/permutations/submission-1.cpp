class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(nums, 0 /*index i*/, res);
        return res;
    }

   private:
    // Invariant:
    // nums[0:i) contains elements of nums picked in previous iterations
    // The subarray nums[i, nums.size()) contains elements of nums not yet picked.
    // We will pick the element for index i from the subarray nums[i, nums.size())
    void backtrack(std::vector<int>& nums, int i,
                   std::vector<std::vector<int>>& res) {
        // Base cases:
        // No more numbers to pick. This is a permutation of nums.
        if (i == nums.size()) {
            res.push_back(nums);
            return; 
        }
        // Recursive case:
        // Pick a number from nums[i, nums.size()) to be at index i in the permutation
        for (int j = i; j < nums.size(); ++j) {
            std::swap(nums[i], nums[j]); // choose
            backtrack(nums, i + 1, res); // explore
            std::swap(nums[i], nums[j]); // unchoose
        }
    }
};
