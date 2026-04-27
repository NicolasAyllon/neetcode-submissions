class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build the graph as an adjacency list:
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            // Get each part of the data
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            // Add a directed edge to the adjacency list
            adj[from].push_back({to, price});
        }

        // Debug
        /*
        for (int i = 0; i < n; ++i) {
            std::cout << "airport " << i << ": ";
            for (const auto& dest_price : adj[i]) {
                int dest = dest_price.first;
                int price = dest_price.second;
                std::cout << "(" << dest << ", $" << price << ")";
            }
            std::cout << "\n";
        }
        */

        // Let's use Breadth First Search (BFS)
        // where we will allow at most k + 1 flights:
        // src -> stop_1 -> stop_2 -> ... stop_k -> dst:

        std::queue<std::pair<int, int>> q; // (node, cumulative_cost_to_reach)

        // Add first node to queue
        q.push({src, 0}); // Getting to src -> src costs $0
        int path_len = 0; // Number of edges traveled (for k stops, there are k + 1 edges)
        int min_cost = std::numeric_limits<int>::max();

        while (!q.empty() && path_len <= k + 1) {
            int num_nodes = q.size();
            // Explore all neighbor airports
            while (num_nodes--) {
                // Pop (node, cost)
                const auto& p = q.front(); q.pop();
                int node = p.first;
                int cost = p.second;
                // If we got to the destination, and it's a lower cost, update min cost
                if (node == dst) {
                    min_cost = std::min(cost, min_cost);
                    continue;
                }
                // We are not at the destination, explore all neighboring airports
                for (const auto& p : adj[node]) {
                    int nei = p.first;
                    int price = p.second;
                    q.push({nei, cost + price});
                }
            }
            // However edges we'd used before, we've now traveled 1 more.
            path_len += 1;
        }

        // Placeholder return value
        return min_cost == std::numeric_limits<int>::max() ? -1 : min_cost;
    }
};
