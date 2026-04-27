class Solution:
    def findMin(self, nums: List[int]) -> int:
        # Raise an exception if the list is empty
        if not nums:
            raise ValueError("List must have at least one element")

        l = 0
        r = len(nums) - 1
        res = nums[0]
        # Invariant: The minimum element is in nums[l, r] OR it is stored in 'res'
        while (l <= r):
            # If the window is already sorted, then pick the leftmost element as the min
            if nums[l] < nums[r]:
                res = min(nums[l], res)
                break

            # The window is not completely sorted
            # Calculate a midpoint index and see which half of the array is sorted
            # We know the sorted portion cannot contain the minium because the rotated portion does
            m = l + (r - l) // 2
            # Capture the midpoint in the result in case it is the minimum
            res = min(nums[m], res)

            if nums[m] >= nums[l]: # nums[l, m] is sorted, and does not contain the min value
                l = m + 1
            else: # nums[m] < nums[l], so nums[l, m] is not sorted and contains the minimum
                # Although nums[m] could be the minimum, we captured it in the result above
                # So we can now focus on nums[l, m-1]
                # Alternative approach is to capture the midpoint in the result here:
                # res = min(nums[m], res)
                r = m - 1
        
        return res

        