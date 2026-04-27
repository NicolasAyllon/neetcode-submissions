class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0
        r = len(heights) - 1
        maxArea = 0

        while l < r:
            width = r - l
            height = min(heights[l], heights[r])
            area = width * height
            maxArea = max(area, maxArea)

            # Advance the index with the shorter height
            if heights[l] >= heights[r]:
                r -= 1
            else: # heights[l] < heights[r]
                l += 1
        
        return maxArea