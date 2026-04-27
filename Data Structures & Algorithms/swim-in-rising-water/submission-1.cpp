class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        const int n = grid.size();
        // Idea: Perform a depth first search for each possible water level, t = 0...n^2-1
        // By the constraint 0 <= grid[i][j] < n^2
        for (int t = 0; t < n*n; ++t) {
            vector<vector<bool>> visited (n, vector<bool>(n, false));
            if (dfs(grid, visited, 0, 0, n-1, n-1, t)) {
                return t;
            }
        }
    }

private:
    bool dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int i_end, int j_end, int t) {
        // Base Cases:
        // Out of bounds, return false
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return false;
        // Can't swim here because elevation is above water level, t.
        if (grid[i][j] > t) return false;
        // Already visited, return false
        if (visited[i][j]) return false;
        // If we're at the destination, return true.
        if (i == i_end && j == j_end) return true;

        // Otherwise, mark visited and explore squares that are reachable at this water level:
        visited[i][j] = true;
        return dfs(grid, visited, i - 1, j, i_end, j_end, t) || // North
               dfs(grid, visited, i, j + 1, i_end, j_end, t) || // East
               dfs(grid, visited, i + 1, j, i_end, j_end, t) || // South
               dfs(grid, visited, i, j - 1, i_end, j_end, t);
        
    }
};
