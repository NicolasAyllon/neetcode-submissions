class Solution {
public:
    // Precondition: nums is not empty.
    // Approach: We'll start with two indices at the left and right ends of the array
    // Pick a middle value. If nums[lo] < nums[mid] then nums[lo, mid] is sorted.
    // Otherwise 
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        // Invariant: if target is present, it will be in the subarray nums[lo, hi]
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // Left portion nums[lo, mid] is sorted
            if (nums[lo] <= nums[mid]) {
                // Target does not lie in this subarray, it lies in the other one.
                if (target < nums[lo] || target > nums[mid]) {
                    lo = mid + 1;
                } 
                // Target is in this subarray, but not at 'mid'
                else {
                    hi = mid - 1;
                }
            }
            // Right portion nums[mid, hi] is sorted
            else {
                // Target does not lie in this subarray, it lies in the other one.
                if (target < nums[mid] || target > nums[hi]) {
                    hi = mid - 1;
                } 
                // Target is in this subarray but not at 'mid'
                else {
                    lo = mid + 1;
                }
            }
        }
        // Subarray [lo, hi] is empty, so target is not present
        return -1;
    }
};
