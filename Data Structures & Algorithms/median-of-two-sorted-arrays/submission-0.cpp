class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // For better performance, we want the first array to be smaller.
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);

        // First notice that if the total number of values is 2k + 1 (odd)
        // then with integer division, (2k + 1) / 2 = k, so middle value is (k + 1)th.
        // Similarly, if the total number of values is 2k (even)
        // then (2k) / 2 = k, so the middle two values are the kth and (k + 1)th
        const int total = nums1.size() + nums2.size();
        const int half = total / 2; // This is the value of k.

        // Perform binary search on nums1, so that we can find a valid partition
        // of nums1 and nums2.
        int lo = 0;
        int hi = nums1.size();

        while (true) {
            // Pick how many values we'll use from nums1.
            // mid is a 0-based index, so we are using the (mid + 1)th value of nums1
            // as the last element of the left partition.
            // We can then calculate the last index of the left parititon of nums2 as:
            int i = (lo + hi) / 2;
            int j = half - i;

            // Calculate the values that might play a role in the median.
            // These will be at the right end of the left partition, 
            // and the left end of the right partition of each array.
            //
            // For out-of-bounds indices: use "-infinity" if the index (i) is before the first (<0)
            // or use "+infinity" if the next index (i + 1) is after the last (>=)
            int nums1_left = (i > 0 ? nums1[i - 1] : std::numeric_limits<int>::min());
            int nums2_left = (j > 0 ? nums2[j - 1] : std::numeric_limits<int>::min());
            int nums1_right = (i < nums1.size() ? nums1[i] : std::numeric_limits<int>::max());
            int nums2_right = (j < nums2.size() ? nums2[j] : std::numeric_limits<int>::max());

            // We have a valid partition
            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                // Return median (even number of values)
                if (total % 2 == 0) {
                    return (std::max(nums1_left, nums2_left) + std::min(nums1_right, nums2_right)) / 2.0;
                    // [ (kth value) + (k+1th value) ] / 2;
                } else {
                    return std::min(nums1_right, nums2_right);
                    // (k+1th value)
                }
            }
            // We chose too many values from nums1.
            else if (nums1_left > nums2_right) {
                // Re-chose an index from before i
                hi = i - 1;
            } 
            // nums2_left > nums1_right
            // We chose too many values from nums2 (not enough from nums1)
            // to make the left partition.
            else {
                // Re-chose an index from after i
                lo = i + 1;
            }
        }
    }
};
