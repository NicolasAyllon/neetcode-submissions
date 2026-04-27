class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Iterate through all nodes in the graph
        // - perform DFS to find all nodes in this connected component, and mark visited
        // - increment count for distinct connected components

        // Build the adjacency list representation of the graph
        // Since edges are undirected, for edge (a, b), b is a's neighbor, and a is b's neighbor
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            int first = edge[0];
            int second = edge[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        // Iterate through each node in the graph, marking all nodes reachable by some path as visited.
        // This makes up one connected component. Continue iterating through the other nodes; if they
        // are not yet visited, they must be part of a different connected component, so start DFS there.
        // Increment connected component count for each top-level call to DFS from this loop.
        std::vector<bool> visited(n);
        int num_connected_components = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited);
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
