class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Use a dictionary (hashmap) to keep track of values seen so far.
        valueToIndex = {}
        for index, num in enumerate(nums):
            complement = target - num
            if complement in valueToIndex:
                return [valueToIndex[complement], index]
            else:
                # There's no index i < j with nums[i] + nums[j] == target
                # Put j in the map nums[j] -> j
                valueToIndex[num] = index
        # For all 0 <= i < j < len(nums) we never found a pair summing to target
        return []
        