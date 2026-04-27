class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjency list
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
        for (const auto& uvt : times) {
            int u = uvt[0];
            int v = uvt[1];
            int t = uvt[2];
            adj[u].push_back({v, t});
        }

        // Next we'll keep track of the current minimum distances from k to all the nodes.
        std::vector<int> dist(n + 1, std::numeric_limits<int>::max());
        dist[k] = 0; // The cost to get from k to k is 0.

        // Create priority queue (min heap) of (dist, vertex) pairs
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            const auto [d, v] = pq.top();
            pq.pop();

            // The first time we saw a node, we recorded the min distance in dist,
            // So, if this entry has a greater distance, it's stale, so we skip.
            // (Note: this is also called lazy deletion, since we don't actually remove
            // the stale entry from the priority queue)
            if (d > dist[v]) continue;

            // d <= dist[v] (first time seeing v)
            // For each neighbor, update the best distance to it.
            for (const auto& [nei, cost] : adj[v]) {
                int new_dist = d + cost;
                if (new_dist < dist[nei]) {
                    // Note this is where we first assign a node's distance.
                    dist[nei] = new_dist;
                    pq.push({new_dist, nei});
                }
            }
        }
        // If all nodes are reachable, then return the maximum distance to any node (starting from k)
        int delay_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == std::numeric_limits<int>::max()) 
                return -1;
            delay_time = std::max(dist[i], delay_time);
        }
        return delay_time;
    }

private:
    void printAdjList(std::unordered_map<int, std::vector<std::pair<int, int>>> adj) {
        for (const auto& [vertex, neighbors] : adj) {
            std::cout << "u = " << vertex << ": ";
            for (const auto& [neighbor, time] : neighbors) {
                std::cout << "(" << neighbor << ", " << time << ") ";
            }
            std::cout << '\n';
        }
    }
};