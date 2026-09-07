class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
        int maxArea = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int area = dfsArea(grid, r, c, rows, cols, visited);
                maxArea = std::max(area, maxArea);
            }
        }

        return maxArea;
    }

private:
    int dfsArea(const std::vector<std::vector<int>>& grid, int r, int c, const int rows, const int cols, std::vector<std::vector<bool>>& visited) {
        // Base case:
        // A square out of bounds contributes no area to an island
        if (r < 0 || r >= rows || c < 0 || c >= cols) return 0;
        // In bounds, but we already visited this square
        if (visited[r][c]) return 0;
        // In bounds, unvisited square but it's water, so it contributes no land area
        if (grid[r][c] == 0) return 0;

        // Recursive case:
        // In bounds, unvisited, and it's land!
        // This square contributes 1 to the total area of the island
        // plus any areas we find by exploring vertically or horizontally
        visited[r][c] = true;
        return 1 + dfsArea(grid, r - 1, c, rows, cols, visited)
                 + dfsArea(grid, r + 1, c, rows, cols, visited)
                 + dfsArea(grid, r, c - 1, rows, cols, visited)
                 + dfsArea(grid, r, c + 1, rows, cols, visited);
    }
};
