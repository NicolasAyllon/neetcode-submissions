class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        // Make a copy of the grid so we can annotate this one
        auto gridCopy = grid;
        int numIslands = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (dfsArea(gridCopy, r, c, rows, cols) > 0) {
                    numIslands++;
                }
            }
        }
        return numIslands;
    }

private:
    // Return the area of the islands containing this square
    // We mark each land square 1 as water 0 once we visit it
    // Note: This function will modify grid, changing all 1s to 0s as it counts island area
    int dfsArea(std::vector<std::vector<char>>& grid, int r, int c, const int rows, const int cols) {
        // Base case:
        // Out of bounds, no more area contributed
        if (r < 0 || r >= rows || c < 0 || c >= cols) return 0;
        // We're at a water square so this doesn't contribute any land area
        if (grid[r][c] == '0') return 0;

        // Recursive case:
        // We're at a land square so this square contributes 1 area, 
        // plus whatever land we find by recursively exploring around
        grid[r][c] = '0'; // mark this land as visited by turning it water
        return 1 + dfsArea(grid, r - 1, c, rows, cols)
                 + dfsArea(grid, r + 1, c, rows, cols)
                 + dfsArea(grid, r, c - 1, rows, cols)
                 + dfsArea(grid, r, c + 1, rows, cols);
    }
};
