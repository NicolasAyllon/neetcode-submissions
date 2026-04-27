class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        int i = 0;
        int sum = 0;
        dfs(nums, i, sum, target, combination, result);
        return result;
    }

private:
    void dfs(std::vector<int>& nums, int i, int sum, int target, 
             std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        // Base Case: we reached the target sum exactly!
        if (sum == target) {
            result.push_back(combination);
            return;
        }
        // Base Case: Overshot the target, can't add any more numbers
        if (sum > target) return;
        // Base Case: No value to consider (index i past end of nums array).
        if (i == nums.size()) return;

        // We have two choices for index i.
        // Case 1. We use it. To allow for using the number again, don't advance index.
        combination.push_back(nums[i]);
        dfs(nums, i, sum + nums[i], target, combination, result);
        // Backtrack by removing nums[i] from the combination.
        combination.pop_back();

        // Case 2. We don't use it, and we move on to the next index.
        dfs(nums, i + 1, sum, target, combination, result);
    }
};
