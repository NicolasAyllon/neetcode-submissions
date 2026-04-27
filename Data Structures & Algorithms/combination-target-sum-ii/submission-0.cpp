class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end()); // Sort so identical values are adjacent.
        int i = 0; // Index we're on, deciding whether to include candidates[i]
        int sum = 0; // Sum of elements in the combination chosen so far.
        dfs(candidates, i, sum, target, combination, result);
        return result;
    }

private:
    void dfs(std::vector<int>& candidates, int i, int sum, int target,
             std::vector<int>& combination, std::vector<std::vector<int>>& result) {
            // Base case: our current sum matches the target, solution found!
            if (sum == target) {
                result.push_back(combination);
                return;
            }
            // Base case: overshot target, or 
            // we ran out of values to consider (i is past the end of the array)
            if (sum > target || i >= candidates.size()) return;

            // Recursive case: (sum < target and i < candidates.size, in bounds)
            // Case 1. Add nums[i] (and possibly more)
            // We can add nums[i] to the combination and advance the index i by 1.
            // This way we can choose to add any duplicate copies of this number that come after it.
            combination.push_back(candidates[i]);
            dfs(candidates, i + 1, sum + candidates[i], target, combination, result);
            combination.pop_back(); // Backtrack

            // Case 2. Don't add any more copies of nums[i]
            // We can skip it, and advance to the next index that 
            // contains a different unique number in candidates
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                ++i;
            // Now either i + 1 == candidates.size() OR candidates[i+1] != candidates[i]
            dfs(candidates, i + 1, sum, target, combination, result);
          }
};
