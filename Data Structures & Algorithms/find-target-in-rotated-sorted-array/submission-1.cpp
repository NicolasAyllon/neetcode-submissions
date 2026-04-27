class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            // Calculate midpoint and see if target is at this index.
            int m = l + (r - l)/2;
            if (nums[m] == target)
                return m;
            // nums[m, r] is sorted
            if (nums[m] < nums[r]) {
                // Target not in this subarray
                if (target < nums[m] || target > nums[r]) {
                    r = m - 1;
                } else { // Target would be found in this part of the array.
                    l = m + 1;
                }
            }
            // nums[m] > nums[r] --> nums[l, m] is sorted
            else {
                // Target not in the sorted subarray
                if (target < nums[l] || target > nums[m]) {
                    l = m + 1;
                } else { // Target would be found in nums[l, m-1]
                    r = m - 1;
                }
            }
        }
        // l > r : The subarray in which TARGET would be found is empty (not found)
        return -1;
    }
};
