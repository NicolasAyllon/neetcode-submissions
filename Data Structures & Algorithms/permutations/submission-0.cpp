class Solution {
public:
    // Note the maximum size of result is 6! = 720
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }

private:
    // We maintain the invariant that the values in nums from index 0 to exclusive
    // contain elements selected from the original array nums.
    void dfs(std::vector<int>& nums, int i, std::vector<std::vector<int>>& result) {

        // Base Case: we've picked elements for indices [0, nums.size())
        // which is all indices. Put this permutation in the result.
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }

        // i < nums.size()
        // nums[0, i) already contains picked elements, and
        // nums[i, nums.size()) contains unpicked elements where we'll draw from.
        
        // Select any index from i to nums.size()-1, and swap the item
        // into this position at index i.
        for (int j = i; j < nums.size(); ++j) {
            // Pick elem at index j to be in position i in the permutation.
            std::swap(nums[i], nums[j]);
            // Recursively pick the rest of the elements.
            dfs(nums, i + 1, result);
            // Backtrack: undo by reversing the swap.
            std::swap(nums[i], nums[j]);
        }
    }
};
