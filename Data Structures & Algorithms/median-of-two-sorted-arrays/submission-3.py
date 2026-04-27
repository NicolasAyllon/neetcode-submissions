class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Eventually we'll perform binary search on one array to find the indices that form a valid partition
        # To minimize the search time, we want the first array to be smaller
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        # Constants, for convenience
        m = len(nums1)
        n = len(nums2)
        count = m + n
        half = (m + n) // 2 # Integer division, num elements in left partition

        # Let nums1[0, i1) contain elements index 0 up to but not including i1 from nums1
        # Let nums2[0, i2) contain elements index 0 up to but not including i2 from nums2
        # For a valid partition we need all elements in union(nums1[0, i1), nums2[0, i2)) 
        # to be less than or equal to all elements in union(nums1[i1+1, m), nums2[i2+1, n))

        # Now perform binary search on nums1 seeking the index i1 such that we have a valid partition
        # Note that since we always want 'half' elements in the left partitions of nums1 and nums2,
        # this fixes i2 as (i1) + (i2) == half -> i2 = half - i1
        # We search nums1[0, m) for the index i1 of a valid partition
        lo = 0
        hi = m
        i1 = i2 = 0 # Placeholder initialization
        while lo <= hi:
            i1 = lo + (hi - lo) // 2
            i2 = half - i1
            # Calculate max of left partitions, min of right partitions
            left_max1 = nums1[i1 - 1] if i1 > 0 else float("-inf")
            left_max2 = nums2[i2 - 1] if i2 > 0 else float("-inf")
            right_min1 = nums1[i1] if i1 < m else float("inf")
            right_min2 = nums2[i2] if i2 < n else float("inf")

            # Valid partition
            if left_max1 <= right_min1 and left_max2 <= right_min1:
                break
            # Too many values from nums1, need to decrease i1
            elif left_max1 > right_min2: 
                hi = i1 - 1
            # Too few values from nums1, need to increase i1
            else: # left_max2 > right_min1
                lo = i1 + 1

        # Now we have a valid partition. Calculate the maxs of the left partitions
        # and the mins of the right partitions
        left_max1 = nums1[i1 - 1] if i1 > 0 else float("-inf")
        left_max2 = nums2[i2 - 1] if i2 > 0 else float("-inf")
        right_min1 = nums1[i1] if i1 < m else float("inf")
        right_min2 = nums2[i2] if i2 < n else float("inf")

        # Even number of values, median is the average (max of the union of left partitions, min of union of right partitions)
        if count % 2 == 0:
            return (max(left_max1, left_max2) + min(right_min1, right_min2)) / 2.0
        # Odd number of values, the median is the smallest value of the union of the right partitions, since 'half' elements are in the left partitions
        else:
            return min(right_min1, right_min2)




