from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        queue = deque()
        # We maintain the invariant that the deque will hold indices whose values in nums
        # are in nonincreasing order. This way, if one falls out of the window, the next largest value
        # (with greater index) is next from the front of the queue
        #
        # indices: front -> (i1 < i2 < i3 < ...) <- back
        # values: nums[i1] >= nums[i2] >= nums[i3] >= ...
        for index, val in enumerate(nums):
            # Put this index in the queue, but to make sure its in nonincreasing order,
            # first pop all indices whose corresponding values are less than this value
            while queue and nums[queue[-1]] < val:
                queue.pop()
            # Now nums[queue[-1]] >= val, which maintains the invariant of nonincreasing order
            queue.append(index)
            # Finally remove any indices from the front of the queue that are outside the window
            while queue[0] <= index - k:
                queue.popleft()
            # Now the deque only contains indices in the window whose corresponding values are in nonincreasing order
            # So, the index at the front of the queue is in the window and has the biggest corresponding value (the window max)
            # Only add the window max to the result when the rightmost index is at least k - 1 (the last index of the first window)
            if index >= k - 1:
                result.append(nums[queue[0]])

        return result