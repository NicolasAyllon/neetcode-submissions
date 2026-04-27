class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)

        left_wall = [0] * n
        left_wall[0] = 0
        for i in range(1, n):
            left_wall[i] = max(height[i-1], left_wall[i-1])
        
        right_wall = [0] * n
        right_wall[n-1] = 0
        for i in range(n-2, -1, -1):
            right_wall[i] = max(height[i+1], right_wall[i+1])

        trapped_water = 0
        for i in range(n):
            water_level = min(left_wall[i], right_wall[i])
            water_above = max(water_level - height[i], 0)
            trapped_water += water_above

        return trapped_water

        