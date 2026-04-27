class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Let 'start' be the starting index of the subarray we're considering
        // Let 'cur_sum' hold the max_sum of any subarray starting at at 'start', ending at i: [start, i)

        int max_sum = nums[0]; // max subarray sum over 0 <= i <= j < nums.size()
        int cur_sum = nums[0]; // max sum ending at index j
        // Max subarray sum up to i exclusive: MAX sum[start, i) for start <= i

        // Iterate through the array:
        for (int j = 1; j < nums.size(); ++j) {
            // Calculate the max subarray sum that ends at this index, j.
            // if 0 <= i < j, then max subarray is: cur_sum + nums[j]
            // if 0 <= i == j, then the subarray is just this value: nums[j]
            // Together, we've covered all cases for 0 <= i <= j.
            cur_sum = std::max(cur_sum + nums[j], nums[j]);
            max_sum = std::max(cur_sum, max_sum);
        }
        return max_sum;
    }
};
