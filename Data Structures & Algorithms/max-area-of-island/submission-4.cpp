class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        int maxArea = 0;
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int area = bfsArea(grid, r, c, rows, cols, visited);
                maxArea = std::max(area, maxArea);
            }
        }

        return maxArea;
    }

private:
    // Returns the area of the island that grid[r][c] is a part of, 
    // provided that we haven't counted its area already in a previous call to bfsArea (using a different point (r', c') on the same island)
    int bfsArea(const std::vector<std::vector<int>>& grid, int r, int c, int rows, int cols, std::vector<std::vector<bool>>& visited) {
        int area = 0;
        std::queue<std::pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            const auto [r, c] = q.front();
            q.pop();

            // Ignore out of bounds
            if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
            // Ignore squares already visited
            if (visited[r][c]) continue;

            // Unvisited square, so first mark it as visited!
            // If it's land, then count the land area as 1, and enqueue the surrounding spaces
            visited[r][c] = true;
            if (grid[r][c] == 1) {
                area += 1;
                q.push({r - 1, c});
                q.push({r, c + 1});
                q.push({r + 1, c});
                q.push({r, c - 1});
            }
        }

        return area;
    }
};
