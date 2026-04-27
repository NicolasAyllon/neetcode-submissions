class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        # Invariant: target, if present, lies in the interval [left, right] (inclusive)
        while left <= right:
            mid = left + (right - left) // 2 # Integer division
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                # target must lie in the interval [mid+1, right]
                left = mid + 1
            else: # nums[mid] > target
                # target must lie in the interval [left, mid-1]
                right = mid - 1
        
        # Target not found (present in an empty interval)
        return -1