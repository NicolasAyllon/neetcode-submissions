class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {} # dictionary holding count of each number
        freq = [[] for i in range(0, len(nums) + 1)] # list of numbers indexed by frequency
        # For example freq[4] = [2, 5] means numbers 2 and 5 both appear 4 times

        for n in nums:
            count[n] = 1 + count.get(n, 0) # get(key, default_value_if_not_present)

        # Put numbers in the array from count -> list of nums with that count
        for n, c in count.items(): # recall .items() returns the (key, value) pairs
            freq[c].append(n)

        topK = []
        c = len(nums)
        while (len(topK) < k and c > 0):
            if (len(freq[c]) > 0):
                topK.append(freq[c].pop())
            else:
                c -= 1

        return topK




        
