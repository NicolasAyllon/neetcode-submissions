class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<bool> picked(nums.size(), false);
        std::vector<std::vector<int>> res;
        std::vector<int> permutation;
        backtrack(nums, picked, permutation, res);
        return res;
    }

private:
    void backtrack(const std::vector<int>& nums, std::vector<bool>& picked, 
                   std::vector<int>& permutation, std::vector<std::vector<int>>& res)  {
        // Base case: we picked every number in nums in some order, to make a permutation
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }
        // Recursive case:
        // We still have 1 or more number to pick.
        // Let's pick 1 number at index i that hasn't been picked yet (picked[i] == false)
        // Then recursively explore permutations after this choice.
        for (int i = 0; i < nums.size(); ++i) {
            if (!picked[i]) {
                permutation.push_back(nums[i]); // choose
                picked[i] = true;
                backtrack(nums, picked, permutation, res); // explore
                permutation.pop_back(); // unchoose, or backtrack
                picked[i] = false;
            }
        }
    }
};
