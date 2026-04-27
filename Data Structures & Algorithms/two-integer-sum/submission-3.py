class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        valToIndex = {}
        for i in range(len(nums)):
            if target - nums[i] in valToIndex:
                return [valToIndex[target - nums[i]], i]
            valToIndex[nums[i]] = i
        return []
        