class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo = 0
        hi = len(nums) - 1
        # Invariant: if target is present, it'll be in nums[lo, hi] inclusive
        while lo <= hi:
            mid = lo + (hi - lo) // 2

            # Target found
            if nums[mid] == target:
                return mid

            # Left subarray nums[lo, mid] is sorted
            if nums[lo] <= nums[mid]:
                # Target does not lie nums[lo, mid]
                if target < nums[lo] or target > nums[mid]:
                    lo = mid + 1
                # Target is in nums[lo, mid] but not at mid
                else:
                    hi = mid - 1

            # Right subarray nums[mid, hi] is sorted
            else:
                # Target does not lie in nums[mid, hi]
                if target < nums[mid] or target > nums[hi]:
                    hi = mid - 1
                # Target lies in nums[mid, hi] but not at mid
                else:
                    lo = mid + 1

        # The interval nums[lo, hi] is empty, so target is not present
        return -1