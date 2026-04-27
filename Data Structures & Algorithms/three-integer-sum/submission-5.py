class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # First sort the list
        nums.sort()

        result = []
        # Now iterate over possible indices i
        # Maintain invariant: i < j < k
        for i in range(len(nums)):
            # Skip duplicate values
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            # Fix i. 
            # Find all j and k with nums[j] + nums[k] == -nums[i] 
            j = i + 1 # index after i
            k = len(nums) - 1 # last index
            while j < k:
                # Found a solution
                if nums[j] + nums[k] == -nums[i]:
                    result.append([nums[i], nums[j], nums[k]])
                    # Advance j and k, skipping any duplicate values
                    while j + 1 < len(nums) and nums[j + 1] == nums[j]:
                        j += 1
                    while k - 1 >= 0 and nums[k - 1] == nums[k]:
                        k -= 1
                    # Now nums[j + 1] != nums[j] and nums[k - 1] != nums[k]
                    j = j + 1
                    k = k - 1

                # Sum too small. Increase j, skipping any duplicate values
                elif nums[j] + nums[k] < -nums[i]:
                    while nums[j + 1] == nums[j] and j < k:
                        j += 1
                    j = j + 1

                # Sum too big. Decrease k, skipping any duplicate values
                else: #nums[j] + nums[k] > -nums[i]
                    while nums[k - 1] == nums[k] and j < k:
                        k -= 1
                    k = k - 1

        return result
            

                    


        