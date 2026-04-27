class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        vals = set(nums)
        # For every possible start of a sequence
        maxSeqLen = 0
        for val in vals:
            # Prev integer not in nums, this is a sequence start
            if val - 1 not in vals:
                # Count length of this sequence starting with val
                seqLen = 1
                nextVal = val + 1
                while nextVal in vals:
                    seqLen += 1
                    nextVal += 1

                maxSeqLen = max(seqLen, maxSeqLen)

        return maxSeqLen
