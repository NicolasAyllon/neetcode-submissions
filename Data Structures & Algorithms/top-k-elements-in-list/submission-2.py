class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        freq = [[] for _ in range(0, len(nums) + 1)]

        for num in nums:
            count[num] = 1 + count.get(num, 0)

        heap = [] # min_heap
        for num, cnt in count.items():
            heapq.heappush(heap, (cnt, num))
            if len(heap) > k:
                heapq.heappop(heap) # pop smallest value (count) in the (count, num) tuple

        print(heap)
        # Now heap contains the (count, num) tuples with the k highest counts
        res = []
        # Add items to result from smallest count to biggest count (since 'heap' is a min heap)
        while (len(heap) > 0 and len(res) < k):
            cnt, num = heapq.heappop(heap)
            res.append(num)

        # Either the heap is empty or we have the top k elements
        # Reverse the list so numbers are in order from biggest count to smallest count
        res.reverse()
        return res
