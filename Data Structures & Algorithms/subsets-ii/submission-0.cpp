class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the array so that duplicate values are adjacent
        std::vector<std::vector<int>> result;
        std::vector<int> subset;
        std::sort(nums.begin(), nums.end());
        dfs(nums, 0 /*index */, subset, result);
        return result;
    }

private:
    void dfs(std::vector<int>& nums, int i, std::vector<int>& subset, std::vector<std::vector<int>>& result) {
        // Base case:
        // We already made decisions about whether to include each number in nums.
        // Add this subset to the result.
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }

        // i < nums.size()
        // We need to make a decision on whether to include nums[i] in the subset.
        // Note that we can't just choose yes/no for each element because
        // for duplicate values, say [1, 2, 2, 2, 3], we could select one of the 2's
        // in three different ways, but we don't want to overcount like this.

        // Case 1. Pick this number and advance 1 index (decide whether to pick any more copies of this number)
        // Then backtrack, so we can explore all subsets that don't include this value.
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, result);
        subset.pop_back();

        // Case 2. Don't pick this number, and advance to the next unique value, skipping over all duplicates of this number.
        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            ++i;
        // Now i + 1 is the index of the next unique value.
        dfs(nums, i + 1, subset, result);
    }
};
