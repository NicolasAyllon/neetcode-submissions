class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Loop through every value in the array
        # For each number, go to that index (0-based) and 
        # flip the sign of the value to negative
        # If we later come to an index where the value has
        # already been made negative, this index corresponds
        # to the duplicate value
        for num in nums:
            idx = abs(num) - 1
            if nums[idx] < 0:
                return abs(num)
            else:
                nums[idx] *= -1
        # No duplicate found, but the problem guarantees a duplicate
        return -1

        