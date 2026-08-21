class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> subsets;
        std::vector<int> subset;
        dfs(nums, 0, subset, subsets);
        return subsets;
    }

private:
    // Recursively process the input array.
    // We need to make a choice for index i: Do we want to include the element nums[i] in the subset?
    // We consider both options (yes/no) and recursively process the rest of nums in both cases.
    void dfs(const std::vector<int>& nums, int i, std::vector<int>& subset, std::vector<std::vector<int>>& subsets) {
        // Base case: no more elements to choose, we made a decision yes/no for every element in nums.
        // Add the current subset to the result.
        if (i == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        // Recursive case:
        // We need to consider both cases for the element at index i in nums:
        // Case 1. We don't include nums[i]. Proceed to make a decision for index i + 1
        dfs(nums, i + 1, subset, subsets);

        // Case 2. We do include nums[i], so add it to the current subset and recursively consider index i + 1.
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, subsets);
        // Backtrack so this decision is not permanent. 
        // We can choose to not include nums[i] for a different history of past decisions for indices < i
        subset.pop_back();
    }
};
