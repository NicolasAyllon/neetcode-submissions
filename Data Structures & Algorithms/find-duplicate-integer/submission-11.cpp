class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Let's use the array itself to track whether we've seen particular values
        // For example if we see 4, we'll go to the corresponding 0-based index (4-1=3)
        // and negate the value there.
        // Later, if see 4 again, we'll go to index (4-1=3) and find that the value there
        // is negative. And since the array started with values in the range [1, n] that means
        // we've already seen 4 before (if the value at index 3 is negative)
        // 
        // Now all we have to do is iterate over the array, and check whether the value at the
        // corresponding 0-based index is negative, and if it is, we know that idx+1 is the
        // duplicate value
        // 
        for (int i = 0; i < nums.size(); ++i) {
            // Get 0-based index for this value. Note we must take the absolute value in case this
            // index was seen before.
            int idx = std::abs(nums[i]) - 1;
            // We've already seen (idx + 1) so it's the duplicate
            if (nums[idx] < 0) {
                return idx + 1;
            }
            // Otherwise, negate the value here to track that we've seen (idx + 1) before
            nums[idx] = -nums[idx];
        }
        // This shouldn't happen, but if there were were no duplicates, return -1
        return -1;
    }
};
