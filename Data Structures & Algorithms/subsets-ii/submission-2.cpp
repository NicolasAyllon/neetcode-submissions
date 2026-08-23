class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // First sort the input array, so that all duplicates are next to each other
        std::sort(nums.begin(), nums.end());
        // Create the result and the temporary, working subset that we're building
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        // Recursively explore all subsets and add each to the result
        backtrack(nums, 0 /*index i*/, subset, res);
        return res;
    }

private:
    // Invariant:
    // subset contains elements chosen from nums and we are deciding whether to include nums[i] in the current subset.
    // We've already made decisions for the previous part of the array, nums[0, i)
    void backtrack(const std::vector<int> nums, int i, 
                   std::vector<int>& subset, std::vector<std::vector<int>>& res) {
        // Base Case:
        // We've made a decision for all vals in input array whether to include it (yes/no), so add it to the result
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        // Recursive case:
        // We haven't reached past the end of nums, and we need to make a decision
        // for nums[i]. There are 2 choices:
        // Case 1.
        // We choose to include nums[i] and we advance to the value at the next index
        // which is possibly a duplicate (nums[i + 1] == nums[i])
        subset.push_back(nums[i]); // choose
        backtrack(nums, i + 1, subset, res); // explore
        subset.pop_back(); // unchoose/backtrack

        // Case 2.
        // We choose not to include nums[i] and this is the last copy of nums[i] we'll ever include
        // To get to the next unique value, we advance i until nums[i + 1] is a different value from nums[i].
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
            i++;
        }
        backtrack(nums, i + 1, subset, res);
    }
};
