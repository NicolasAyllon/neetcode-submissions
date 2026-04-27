class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        // Pass 1: find the height of the highest bar to the left of each index 
        // (i.e. the height of the left wall)
        // The highest bar to the left of index 0, is, let's say, 0.
        std::vector<int> left_wall(n, 0);
        left_wall[0] = 0;
        for (int i = 1; i < n; ++i) {
            left_wall[i] = std::max(height[i-1], left_wall[i-1] /*max(height[0],...height[i-2]) */);
        }
        // The highest bar to the right of index n-1, is, let's say, 0, because no water can be trapped here
        std::vector<int> right_wall(n, 0);
        right_wall[n-1] = 0;
        for (int i = n-2; i >= 0; --i) {
            right_wall[i] = std::max(height[i+1], right_wall[i+1] /*max(height[i+2],...height[n-1]) */);
        }

        // Finally, calculate the height of water at each index.
        int trapped_water = 0;
        for (int i = 0; i < n; ++i) {
            int water_level = std::min(left_wall[i], right_wall[i]);
            int water_above = std::max(water_level - height[i], 0);
            trapped_water += water_above;
        }
        return trapped_water;
    }
};
