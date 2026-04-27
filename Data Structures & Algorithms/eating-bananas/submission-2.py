class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        lo = 1
        hi = max(piles)
        minK = float('inf')

        # Invariant: [lo, hi] inclusive is the unsearched part of the array
        while lo <= hi:
            k = lo + (hi - lo) // 2
            hours = hoursToEat(piles, k)
            if hours <= h:
                # Goal achieved. Save this value of k
                minK = min(k, minK)
                # See if we can find an even smaller value of k, search [lo, k-1]
                hi = k - 1
            else: # hours > h
                # Too slow. We don't need to consider values of k lo...k, now search [k+1, hi]
                lo = k + 1

        # No part of the array is unsearched. We have the smallest value of k
        return minK

def hoursToEat(piles: List[int], k: int) -> int:
    hours = 0
    for bananas in piles:
        hours += (bananas + k - 1) // k
        print(f"hours = {hours}")
    return hours