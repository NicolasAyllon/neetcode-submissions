class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> combination;
        dfs(nums, 0, 0, target, combination, res);
        return res;
    }

   private:
    void dfs(const std::vector<int>& nums, int i, int sum, int target, std::vector<int>& combination,
             std::vector<std::vector<int>>& res) {
        // Base cases:
        // We exceeded the target, so don't add this combination to the result, and return
        if (sum > target) return;
        // We reached the target exactly, so add this combination to the result and return
        if (sum == target) {
            res.push_back(combination);
            return;
        }
        // Sum is less than the target, but we have no more numbers to pick
        if (i == nums.size()) return;

        // Recurisve case: we didn't reach the target (sum < target) 
        // and we are still considering adding a copy of nums[i]
        // We have two choices:
        // Case 1. we don't add any copies of this number, and we move on to the next index (i + 1)
        dfs(nums, i + 1, sum, target, combination, res);
        // Case 2. we add a copy of this number, with the option to add more later (don't advance index i)
        combination.push_back(nums[i]);
        dfs(nums, i, sum + nums[i], target, combination, res);
        // We backtrack so that we can undo this choice, 
        // so we can make it again for a different history of past decisions (callstack)
        combination.pop_back();
    }
};
