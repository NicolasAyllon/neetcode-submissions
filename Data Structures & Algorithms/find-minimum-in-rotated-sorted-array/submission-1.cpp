class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = (lo + hi)/2;
        
        // Array is not rotated, return first value as the min.
        if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi])
            return nums[lo];
        
        std::cout << "findMin: lo = " << lo << ", mid = " << mid << ", hi = " << hi << '\n';
        // Otherwise, array has been rotated
        return doFindMin(nums, lo, hi);
    }

private:
    int doFindMin(const vector<int>& nums, int lo, int hi) {
        std::cout << "doFindMin: lo = " << lo << ", hi = " << hi << '\n';
        // Interval [lo, hi] is just 1 value, return it.
        if (hi - lo == 1)
            return nums[hi];

        // Calculate midpoint
        int mid = (lo + hi)/2;
        // Midpoint lower than left, min-value is in [lo, mid]
        if (nums[lo] > nums[mid]) {
            return doFindMin(nums, lo, mid);
        } 
        // Midpoint value is higher than left, so [lo, mid] is sorted.
        // The discontinuity where the value jumps from the max to min must be in
        // the interval [mid, hi].
        else {
            return doFindMin(nums, mid, hi);
        }
    }
};
