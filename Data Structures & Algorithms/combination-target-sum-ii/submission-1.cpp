class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> combination;
        // To aid in creating unique subsets, we'll sort the candidates array
        // This way, if we choose not to include the value at candidates[i], we advance to the next unique value
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0 /*index i*/, 0 /*sum*/, target, combination, res);
        return res;
    }

   private:
    void backtrack(const std::vector<int>& candidates, int i, int sum, int target,
                   std::vector<int>& combination, std::vector<std::vector<int>>& res) {
        // Base cases:
        // Case 1. sum exceeds the target, so adding more numbers can't help
        if (sum > target) return;
        // Case 2. we met the target! Add a copy of the current combination to the result
        if (sum == target) {
            res.push_back(combination);
            return;
        }
        // Case 3. We are less than the target, and there are no more numbers from the candidates array we can add
        if (i >= candidates.size()) return;

        // Recursive case:
        // sum < target and there are still more numbers in the candidates array to possibly choose
        // For candidates[i], we can either choose it, or we can skip it.
        // 
        // But we want to make sure there are no duplicate combinations, so if we skip this value,
        // we don't want to include any future copies of this value.
        //
        // One way we can ensure this is to first sort the candidates array, and then, if we choose to skip
        // this copy of candidates[i], to advance to the next unique value
        //
        // Case 1. We take one copy of candidates[i] in the subset, and move to the next index
        combination.push_back(candidates[i]); // choose
        backtrack(candidates, i + 1, sum + candidates[i], target, combination, res);
        combination.pop_back();
        // Case 2. We don't take a copy of candidates[i] and move all the way to the next unique value
        int i_next = i + 1;
        while (i_next < candidates.size() && candidates[i_next] == candidates[i]) {
            i_next++;
        }
        // Now candidates[i_next] != candidates[i] and candidates[i_next] is the next unique value
        // OR i_next is an index past the end of the candidates array
        backtrack(candidates, i_next, sum, target, combination, res);
    }
};
