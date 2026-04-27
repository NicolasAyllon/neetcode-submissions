class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        // Array already sorted.
        if (nums[0] < nums[n-1])
            return bsearch(nums, target, 0, n-1);

        // Array is rotated.
        // Use binary search to find the indices where the array wraps.
        // That is, consecutive indices (lo, hi) where
        // nums[lo] is the max, and nums[hi] is the min.
        int lo = 0;
        int hi = nums.size() - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo)/2;
            // nums[mid, hi] is sorted
            // wrap indices must be in [lo, mid]
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } 
            else { // nums[mid] > nums[hi]
            // nums[lo, mid] is sorted
            // wrap indices must be in [mid, hi]
                lo = mid;
            }
        }

        // Target is in the sorted portion [0, lo]
        if (target >= nums[0] && target <= nums[lo])
            return bsearch(nums, target, 0, lo);
        // Target is in the sorted portion [hi, n-1]
        if (target >= nums[hi] && target <= nums[n-1])
            return bsearch(nums, target, hi, n-1);
        // Not reached: target not in [min, max]
        return -1;
    }

private:
    // Recursive binary search subroutine.
    int bsearch(const vector<int>& nums, int target, int lo, int hi) {
        // Target will be found in an empty subarray (not found)
        if (lo > hi) 
            return -1;

        // Look at value at midpoint index
        int mid = lo + (hi - lo)/2;

        // Target at this index!
        if (nums[mid] == target) {
            return mid;
        } 
        // Target in [mid+1, hi]
        else if (nums[mid] < target) {
            return bsearch(nums, target, mid + 1, hi);
        } 
        // target in [lo, mid-1]
        else { // nums[mid] > target
            return bsearch(nums, target, lo, mid - 1);
        }
    }
};
