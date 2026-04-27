class Solution {
public:
    // Approach:
    // Without merging the arrays, use two indices i1 and i2 into nums1 and nums2
    // And these will mark the end of a partition of both arrays
    //
    // Since the arrays are sorted, we already know that nums1[i1] <= nums1[i1+1] and nums2[i2] <= nums2[i2+1]
    // To ensure that the values in UNION(nums1[0, i1), nums2[0, i2)) form a valid partition, they must be less than or equal to
    // the remaining values which form the right half (UNION(nums1[i1+1, M), nums2[i2+1, N))
    //
    // That is, we check if:
    //  * the greatest value in the left partition of nums1 is <= the smallest value in the right partition of nums2
    //  * the greatest value in the left partition of nums2 is <= the smallest value in the right partition of nums1
    //
    // If both conditions are met, it's a valid partition, and we can find the median if the size of the left partition
    // contains half the data values.

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Without loss of generality, we want to perform binary search for a valid partition on the smaller array
        // We require the first array to be the smaller one.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // To make handling the case where we pick no values from one of the arrays, prepend -inf and append +inf to both arrays
        // Since this will not affect the median.

        // Now we know nums1.size() <= nums2.size(), so nums1 is the smaller array.
        const int m = nums1.size();
        const int n = nums2.size();
        const int count = m + n;
        const int half = (m + n) / 2; // Number of values in the left partitions
        // integer division: if count == 2k (even), then half = k. If count == 2k + 1, then half == k
        //  if count is even, then the median is the average of the k'th and (k+1)'th values
        //  if count is odd, the median is (k+1)'th value

        // Now perform binary search on nums1, where we seek an index i1
        // We seek a partition of nums1[0, i1) meaning from 0 to i1 excluded
        int lo = 0;
        int hi = m;
        int i1, i2;
        int nums1_left_max, nums1_right_min, nums2_left_max, nums2_right_min;
        while (lo <= hi) {

            // Choose the midpoint as i1, and calculate i2 so that there are 'half' total values in both partitions
            // (with i2 fixed from (i1) + (i2) == half)  ->  i2 = half - i1
            i1 = lo + (hi - lo)/2;
            i2 = half - i1;

            nums1_left_max = i1 > 0 ? nums1[i1-1] : std::numeric_limits<int>::min();
            nums2_left_max = i2 > 0 ? nums2[i2-1] : std::numeric_limits<int>::min();
            nums1_right_min = i1 < m ? nums1[i1] : std::numeric_limits<int>::max();
            nums2_right_min = i2 < n ? nums2[i2] : std::numeric_limits<int>::max();

            // Valid partition
            if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
                break;
            }
            // Too many values from nums1. Need fewer values from nums1
            else if (nums1_left_max > nums2_right_min) {
                hi = i1 - 1;
            } 
            // Too many values from nums2. Need more values from nums1
            // nums2_left_max > nums1_right_min
            else {
                lo = i1 + 1;
            }
        }

        // We found a valid partition nums1[0, i1) and nums2[0, i2)
        // For an even number of values, we average the greatest value of the left partitions with the smallest value of the right partitions
        nums1_left_max = i1 > 0 ? nums1[i1-1] : std::numeric_limits<int>::min();
        nums2_left_max = i2 > 0 ? nums2[i2-1] : std::numeric_limits<int>::min();
        nums1_right_min = i1 < m ? nums1[i1] : std::numeric_limits<int>::max();
        nums2_right_min = i2 < n ? nums2[i2] : std::numeric_limits<int>::max();

        if (count % 2 == 0) {
            return (std::max(nums1_left_max, nums2_left_max)
                    + std::min(nums1_right_min, nums2_right_min)) / 2.0;
        }
        // For an odd number of values, the median is the smallest value in the right partitions
        else {
            return std::min(nums1_right_min, nums2_right_min);
        }
    }
};
