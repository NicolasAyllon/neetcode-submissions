class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list where adj[u] is a list of (neighbor, cost) pairs.
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1); // size n+1 to index 1...n
        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back({v, t});
        }

        // Track visited nodes
        std::vector<bool> visited(n + 1, false);
        int num_visited = 0;
        std::queue<std::pair<int, int>> q;
        q.push({k, 0});

        // Track reach times of all nodes with the minimum found so far, until all edges have been visited.
        std::vector<int> dist(n + 1, std::numeric_limits<int>::max()); // index 1...n
        dist[k] = 0;
        // Perform BFS using a standard (normal) queue.
        while (!q.empty()) {
            // Pop (node, t_to_reach) off queue and update reach time if a shorter one was found.
            auto cur = q.front(); q.pop();
            int node = cur.first;
            int traveled = cur.second;

            // Mark visited and add all (neighbor, time_to_reach) pairs to queue.
            if (!visited[node]) {
                visited[node] = true;
                num_visited += 1;
            }
            if (dist[node] < traveled) continue; // This path is longer than ones found already.

            for (const auto& edge : adj[node]) {
                int nei = edge.first;
                int t_edge = edge.second;
                if (traveled + t_edge < dist[nei]) {
                    dist[nei] = traveled + t_edge;
                    q.push({nei, traveled + t_edge});
                }
            }
        }
        return num_visited == n ? *std::max_element(dist.begin() + 1, dist.end()) : -1;
    }
};