class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Put all elements in a hash set
        numSet = set(nums)
        # For each number:
        maxSeqLength = 0
        maxSeq = []
        for num in nums:
            # If it is a possible consecutive sequence start
            if num - 1 not in numSet:
                seq = [num]
                length = 1
                nextNum = num + 1
                while nextNum in numSet:
                    seq.append(nextNum)
                    length += 1
                    nextNum += 1
                print("Found seq = {}".format(seq))
                if length > maxSeqLength:
                    print("New longest sequence found!")
                    maxSeqLength = length
                else:
                    print("Longest sequence is still: {}".format(maxSeq))
        
        return maxSeqLength