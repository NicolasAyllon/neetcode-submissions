class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // First build the adjacency list representation of the graph
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            // Add each node to the other's neighbor list
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Now use depth-first search to explore the graph
        // - keep track of whether a node is visited on the current path
        // - also keep a count for ease of implementation
        std::vector<bool> visited(n, false);
        int count_visited = 0;
        // If we have a valid tree, we can choose any node AND:
        // 1. There is a path to all other nodes in the graph.
        // 2. We will never encounter a previously visited node.
        //    (That would mean there's a cycle, which is not a valid tree)
        int start_node = 0;
        int prev_node = -1;
        if (!dfs(prev_node, start_node, adj, visited, count_visited)) {
            return false;
        }
        // Now we know dfs() returned true, so there are no cycles
        // Finally, we need to check that all nodes were visited
        return count_visited == n;
    }

    bool validTreeAlternative(int n, vector<vector<int>>& edges) {
        /* Not yet implemented */
        return false;
    }

private:
    bool dfs(int prev, int at, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int& count_visited) {
        // Base case:
        if (visited[at]) return false;

        // Recursive case:
        visited[at] = true;
        count_visited++;
        // For each neighbor, recursively explore
        for (int next : adj[at]) {
            // Prevent dfs from going back along the same edge
            if (next == prev) continue;
            if (!dfs(at, next, adj, visited, count_visited))
                return false;
        }
        return true;
    }
};
