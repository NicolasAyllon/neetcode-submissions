class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> subset;
        create_subset(nums, 0, subset, result);
        return result;
    }

private:
    // i is the index we're currently deciding whether to include nums[i]
    // We've already made a decision for previous indices < i.
    void create_subset(std::vector<int>& nums, int i, 
                       std::vector<int>& subset, std::vector<std::vector<int>>& result) {
        // We went through indices i = 0...nums.size()-1
        // and made a decision whether to include or exclude each value in nums,
        // so our subset is complete. Add to result and return.
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }
        // We can either include this value at index i.
        subset.push_back(nums[i]);
        // Adds all subsets that contain nums[i] to the result.
        create_subset(nums, i+1, subset, result);
        // Now we remove nums[i] (backtack)
        subset.pop_back();
        // Add all subsets that do not contain nums[i] to the result.
        create_subset(nums, i+1, subset, result);
    }
};
