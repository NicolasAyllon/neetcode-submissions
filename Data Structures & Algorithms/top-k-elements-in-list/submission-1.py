class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        freq = [[] for _ in range(0, len(nums) + 1)]

        for num in nums:
            count[num] = 1 + count.get(num, 0)
        for num, cnt in count.items():
            freq[cnt].append(num)

        res = []
        cnt = len(nums)
        while len(res) < k and cnt > 0:
            if len(freq[cnt]) > 0:
                res.append(freq[cnt].pop())
            else:
                cnt -= 1

        return res





        
