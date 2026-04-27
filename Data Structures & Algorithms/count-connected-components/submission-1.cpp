class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            int first = edge[0];
            int second = edge[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        // Perform BFS to mark all nodes in a connected component as visited, then increment count.
        // If a node in this top-level loop is not yet visited, it must be a part of a new connected component.
        std::vector<bool> visited(n, false);
        std::queue<int> q; // Invariant: only unvisited nodes are in the queue
        int num_connected_components = 0;
        for (int i = 0; i < n; ++i) {
            // Perform BFS from i
            if (!visited[i]) {
                q.push(i);
                while (!q.empty()) {
                    int at = q.front(); 
                    q.pop();
                    visited[at] = true;
                    for (int nei : adj[at]) {
                        if (!visited[nei])
                            q.push(nei);
                    }
                }
                num_connected_components++;
            }
        }
        return num_connected_components;
    }

private:
    // Precondition
    void dfs(int at, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
        // Base case: if already visited, just return
        if (visited[at]) return;
        // Recursive case: Mark visited and explore all neighbors
        visited[at] = true;
        for (int nei : adj[at]) {
            dfs(nei, adj, visited);
        }
    }
};
