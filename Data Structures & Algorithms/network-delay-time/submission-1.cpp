class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list representation of the graph, 
        // where adj[i] = {(j1, w1), (j2, w2), ... } contains 
        // (node, weight) pairs representing an edge from i->j with weight w
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        for (const auto& uvt : times) {
            int u = uvt[0], v = uvt[1], t = uvt[2];
            adj[u].push_back({v, t});
        }
        // Create min-heap of edge = (path_cost_from_k_to_node, node) pairs.
        // For min heap, invariant is that the child's cost is greater than the parent's.
        auto comp = [] (const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return p1.first > p2.first; // first element is cost
        };
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            decltype(comp)> 
                                min_heap(comp);

        // Track visited nodes and current min cost to get to each node
        std::vector<bool> visited(n + 1, false);
        int num_visited = 0;

        // Push first edge on queue.
        min_heap.push({0, k});

        // While the priority queue is not empty
        while (!min_heap.empty()) {
            // Pop off edge
            auto [path_cost, node] = min_heap.top();
            min_heap.pop();
            // If already visited, continue
            if (visited[node]) continue;
            // Otherwise, this is the first time we are at this node. Mark visited.
            visited[node] = true;
            num_visited += 1;
            // Push all edges to unvisited neighbors onto pq
            for (auto [nei, edge_cost] : adj[node]) {
                min_heap.push({path_cost + edge_cost, nei});
            }
            // If this was the last node to visit, we found the minimum path length
            if (num_visited == n)
                return path_cost;
        }
        // We looked at all edges but didn't visit all nodes.
        // Since there are some nodes the signal can't reach, return -1.
        return -1;
    }
};