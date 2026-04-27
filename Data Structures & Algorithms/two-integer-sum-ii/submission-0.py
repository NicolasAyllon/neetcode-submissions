class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # We maintain the loop invariant that there is no solution
        # for numbers[i'] + numbers[j'] == target
        # with i' < i or j' > j
        i = 0;
        j = len(numbers) - 1

        while i < j:
            if numbers[i] + numbers[j] == target:
                return [i + 1, j + 1] # 1-based indices
            elif numbers[i] + numbers[j] < target:
                # Since numbers is sorted, any i' <= i does not meet the target
                # So, it is true that any i' < i + 1 doesn't meet the target.
                # We update i to i + 1 and maintain the variant
                i += 1
            else: # numbers[i] + numbers[j] > target
                # Any j' >= j also is too big, so any j' > j - 1 doesn't meet the target
                # We update j to j - 1 and maintain the invariant
                j -= 1

        # No solution found
        return []
        
        