class Solution {
public:

    // Approach 2: Dijkstra's Algorithm
    // Use a priority queue to track the frontier of a breadth first search BFS
    // Goal: minimize the maximum height square along the path.
    struct frontier {
        int i; // i-coordinate of frontier
        int j; // j-coordinate of frontier
        int h; // maximum; height seen along the way
    };

    // Method: (Greedily) explore the min-height square of the frontier -> use a min-heap.
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();

        // 1. Create the min heap of (i, j) pairs with respect to the height, grid[i][j]
        // We want the child's grid height to be greater than its parent's, so the heap invariant is:
        auto compare = [] (const frontier& child, const frontier& parent) {
            return child.h > parent.h;
        };
        // Now create the priority queue, using the comparison (heap-invariant) from the lambda above.
        std::priority_queue<frontier, std::vector<frontier>, decltype(compare)> min_heap(compare);
        // Also track whether each node is visited.
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::vector<std::vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // Put start point (0, 0) in the heap.
        // We will mark a node as visited when it's first popped from the heap and examined.
        min_heap.push(frontier{0, 0, grid[0][0]});
        
        while (!min_heap.empty()) {
            // Pop (i, j). This position has the minimum of all frontier's h-values, the max-height-along-path
            frontier p = min_heap.top();
            min_heap.pop();
            int i = p.i, j = p.j, h = p.h;

            // If this node is the destination, then return the minimum height recorded along its path.
            if (i == n-1 && j == n-1) return h;

            // This node isn't the destination...
            // If we've already visited it, skip. Otherwise, mark visited.
            if (visited[i][j]) continue;
            visited[i][j] = true;

            // Add all in-bounds neighbors to heap, along with the maximum value seen so far.
            for (auto dir : directions) {
                int i_next = i + dir[0];
                int j_next = j + dir[1];
                // Out of bounds
                if (i_next < 0 || i_next == n || j_next < 0 || j_next == n) continue;
                // In bounds: push coordinates and max height along path.
                int h_next = std::max(h, grid[i_next][j_next]);
                min_heap.push({i_next, j_next, h_next});
            }
        }
        // We shouldn't reach this point, but return a value anyway so that all execution paths rerturn a value.
        return -1;
    }

};
