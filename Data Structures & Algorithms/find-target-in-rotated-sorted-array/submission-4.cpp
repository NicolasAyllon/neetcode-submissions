class Solution {
public:
    // Precondition: nums is not empty.
    // Approach: We'll start with two indices at the left and right ends of the array
    // Pick a middle value. If nums[lo] < nums[mid] then nums[lo, mid] is sorted.
    // Otherwise 
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        // We maintain the invariant that if target is in nums, it is in the subarray nums[lo, hi]
        while (lo <= hi) {
            std::cout << "Searching lo = " << lo << ", hi = " << hi << '\n';
            // Calculate midpoint index
            int mid = lo + (hi - lo) / 2;
            std::cout << "mid = " << mid << '\n';
 
            // Target found
            if (target == nums[mid]) {
                std::cout << "Target " << target << " found at index " << mid << ". Returning...\n";
                return mid;
            }

            // Left subarray nums[lo, mid] is sorted
            if (nums[lo] <= nums[mid]) {
                std::cout << "nums[" << lo << "] = " << nums[lo] << " < nums[" << mid << "] = " << nums[mid] << '\n';
                std::cout << "left subarray is sorted\n";
                // Target would lie in this subarray
                if (nums[lo] <= target && target <= nums[mid]) {
                    std::cout << "target = " << target << " is in left subarray\n";
                    hi = mid - 1;
                }
                // Target would lie in the other subarray
                else {
                    std::cout << "target = " << target << " must be in right (unsorted) subarray";
                    lo = mid + 1;
                }
            }
            // Right subarray nums[mid, hi] is sorted
            else {
                std::cout << "nums[" << mid << "] = " << nums[mid] << " < nums[" << hi << "] = " << nums[hi] << '\n';
                std::cout << "right subarray must be sorted\n";
                // Target would lie in this subarray
                if (nums[mid] <= target && target <= nums[hi]) {
                    std::cout << "target = " << target << " is in right subarray\n";
                    lo = mid + 1;
                }
                // Target would lie in the other subarray
                else {
                    std::cout << "target = " << target << " must be in left (unsorted) subarray\n";
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};
