class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        const int n = grid.size();
        // Idea: Perform a depth first search for each possible water level, t = 0...n^2-1
        // By the constraint 0 <= grid[i][j] < n^2
        vector<vector<bool>> visited (n, vector<bool>(n, false));
        for (int t = 0; t < n*n; ++t) {
            if (dfs(grid, n, visited, t, 0, 0, n - 1, n - 1)) {
                return t;
            }
        }
    }

private:
    bool dfs(const vector<vector<int>>& grid, int n, vector<vector<bool>>& visited, int t, int i, int j, int i_end, int j_end) {
        // Base Cases:
        // Out of bounds, return false
        if (i < 0 || i >= n || j < 0 || j >= n) return false;
        // Can't reach because water level is too low.
        if (grid[i][j] > t) return false;
        // Already visited, return false
        if (visited[i][j]) return false;
        // If we're at the destination, return true.
        if (i == i_end && j == j_end) return true;

        // Otherwise, mark visited and explore squares that are reachable at this water level:
        visited[i][j] = true;
        bool path_exists_north = dfs(grid, n, visited, t, i-1, j, i_end, j_end);
        bool path_exists_east = dfs(grid, n, visited, t, i, j+1, i_end, j_end);
        bool path_exists_south = dfs(grid, n, visited, t, i+1, j, i_end, j_end);
        bool path_exists_west = dfs(grid, n, visited, t, i, j-1, i_end, j_end);
        visited[i][j] = false;
        return path_exists_north || path_exists_east || path_exists_south || path_exists_west;
    }
};
