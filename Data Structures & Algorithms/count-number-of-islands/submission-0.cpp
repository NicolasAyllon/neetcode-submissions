class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int num_islands = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(grid, i, j, visited) > 0)
                    num_islands++;
            }
        }
        return num_islands;
    }

private:
    // Return the size of the island at i, j
    int dfs(const vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        // Base cases:
        // Out of bounds
        if (i < 0 || i >= grid.size() || 
            j < 0 || j >= grid[0].size()) return 0;
        // Water (not land)
        if (grid[i][j] == '0') return 0;
        // Already visited
        if (visited[i][j] == true) return 0;
        // Recursive case:
        // Mark visited and explore all adjacent squares
        visited[i][j] = true;
        return 1 + dfs(grid, i+1, j, visited) 
                + dfs(grid, i, j+1, visited) 
                + dfs(grid, i-1, j, visited) 
                + dfs(grid, i, j-1, visited);
    }
};
