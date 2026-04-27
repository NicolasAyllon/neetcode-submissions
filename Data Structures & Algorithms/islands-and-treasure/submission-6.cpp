class Solution {
public:
        // Use Breadth-First-Search (BFS) to explore the grid:
        //
        // Starting from each treasure chest (0) 
        // Let grid[i][j] hold the distance from this space
        //   to the nearest treasure chest.
        // For each 4-directionally adjacent square,
        //   We could reach it by stepping there from here
        //   and the distance would be grid[i][j] + 1.
        // 
        // Note: since BFS explores closest squares first,
        // once a square has a distance assigned to it,
        // A shorter path will never be found...so the decision is final.

    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        const int INF = std::numeric_limits<int>::max();
        std::cout << "Using INF = " << std::to_string(INF) << std::endl;

        // Invariant: q contains positions that can reach a treasure chest.
        // AND grid[i][j] already has the distance to the nearest chest as grid[i][j].
        // Notice the invariant holds for the treasure chests themselves 
        // because grid[i][j] = 0 for those positions.
        std::queue<std::pair<int, int>> q;

        // Add treasure chests to queue.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        // While the queue is not empty
        while (!q.empty()) {
            // All positions in the queue are an equal distance away from treasure, process them all.
            
            int sz = q.size(); // Note: this batching positions based on distance from treasure may not be needed.
            while (sz--) {
                // Pop position and save distance.
                auto [i, j] = q.front();
                int dist = grid[i][j];
                q.pop();
                // For every adjacent square that is in-bounds, unexplored-land (INF)
                // Write its distance into the square, and add to queue.
                if (i-1 >= 0 && grid[i-1][j] == INF) {
                    grid[i-1][j] = dist + 1;
                    q.push({i-1, j});
                }
                if (j+1 < n && grid[i][j+1] == INF) {
                    grid[i][j+1] = dist + 1;
                    q.push({i, j+1});
                }
                if (i+1 < m && grid[i+1][j] == INF) {
                    grid[i+1][j] = dist + 1;
                    q.push({i+1, j});
                }
                if (j-1 >= 0 && grid[i][j-1] == INF) {
                    grid[i][j-1] = dist + 1;
                    q.push({i, j-1});
                }
            }
        }
    }
};
