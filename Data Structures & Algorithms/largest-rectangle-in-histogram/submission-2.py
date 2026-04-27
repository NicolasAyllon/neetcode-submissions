class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea = 0
        stack = [] # (index, height) pairs

        for i, h in enumerate(heights):
            start = i # Extend this index as far left as possible, for a rectangle of height h
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                start = index # We can extend the rectangle at height h, back to this index, since height > h
                maxArea = max(maxArea, height * (i - index))
            # Add this (index, height) pair to the stack
            stack.append((start, h))
        
        # Process all the rectangles that can extended all way to the right end of the histogram
        while stack:
            index, height = stack.pop()
            maxArea = max(maxArea, height * (len(heights) - index))
        
        return maxArea
