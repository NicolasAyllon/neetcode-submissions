class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        int sum = 0;
        int i = 0;
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

        // Try adding one of each number at index i or a later index.
        // Start at i to allow for nums[i] to be picked more than once.
        for (int j = i; j < nums.size(); ++j) {
            combination.push_back(nums[j]);
            dfs(nums, j, sum + nums[j], target, combination, result);
            combination.pop_back();
        }
    }
};
