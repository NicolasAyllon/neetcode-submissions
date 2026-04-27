class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            // [mid, hi] is sorted
            if (nums[mid] < nums[hi]) {
                // min must be in [lo, mid]
                hi = mid;
            } 
            // nums[mid] > nums[hi]
            else {
            // So, [lo, mid] is sorted and min-element must be in [mid+1, hi]
                lo = mid + 1;
            }
        }
        // lo == hi and this index has the min element.
        return nums[lo];
    }
};
