class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list representation for the graph
        // where adj[u] is the list of (v, t) pairs for each of u's neighbors, v
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            adj[u].push_back({v, t});
        }

        // Create min-heap of edges (v, t)
        // For a min heap, we want the child (v, t) to have a time t that is greater than the parent's.
        // Define a lambda to use as the comparison for the times t (second element in (v, t))
        auto compare = [] (const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second > b.second; };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> min_t_heap(compare);
        // Add all the starting node n's (neighbor, reach_time) pairs to the min_t_heap.
        for (const auto& vt : adj[k]) {
            min_t_heap.push(vt);
        }
        // The heap will hold the pairs (node, reach_time) where reach_time is the cumulative time to get from start k -> node

        // Track visited nodes
        std::vector<bool> visited(n + 1, false); // size n+1 to index 1...n
        visited[k] = true;
        int num_visited = 1;

        // Save elapsed time to get to the current node, starting with k
        int t_elapsed = 0;
        
        // Now use BFS (breadth first search) to explore the graph in the order of least-time-cost edges.
        // Each edge 
        while (!min_t_heap.empty()) {
            // Pop edge from queue.
            auto cur = min_t_heap.top();
            int node = cur.first;
            int reach_time = cur.second;
            min_t_heap.pop();

            // If this node was already visited, don't process.
            if (visited[node]) continue;

            // Otherwise, we're visiting it for the first time.
            visited[node] = true;
            num_visited += 1;
            t_elapsed = reach_time;

            // Add all its (neighbor, reach_time) pairs to the 
            // where reach_time is the sum of the time to get here, plus the cost to get to the neighbor
            for (const auto& vt : adj[node]) {
                int nei = vt.first;
                int edge_time = vt.second;
                if (!visited[nei]) {
                    min_t_heap.push({nei, reach_time + edge_time});
                }
            }
        }

        // Not possible to reach all nodes
        return num_visited == n ? t_elapsed : -1;
    }
};