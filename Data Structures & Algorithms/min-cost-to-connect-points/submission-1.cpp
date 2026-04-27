class Solution {
public:
    // Method 2: Prim's Algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        // We don't need an adjacency list because we can connect any two vertices.
        // In other words, there is a potential edge between any two vertices.
        const int n = points.size();
        std::vector<bool> visited(n, false);

        // Create a priority queue of (distance/cost, end_node) pairs, which is a min-heap with respect to distance (cost)
        // The min-heap will maintain that each child (a) is greater its parent (b).
        auto compare = [](std::pair<int, int>& a, std::pair<int, int>& b) {
            return a.first > b.first;
        };
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            decltype(compare)> min_heap(compare);
    
        // We mark a node as visited when an edge connecting it is added to the MST.
        min_heap.push({0, 0}); // Start with (cost=0, node=0)
        int total_cost = 0;
        int num_visited = 0;
        
        while (!min_heap.empty() && num_visited < n) {
            // Pop edge from queue
            auto p = min_heap.top(); min_heap.pop();
            int dist = p.first;
            int node = p.second;
            // If this node was already visited (in the MST) continue
            if (visited[node]) continue;
            // Otherwise this is the cheapest edge connecting to the current MST that adds an unvisited node.
            // Mark visited and add this node to the MST. Also update the total cost.
            visited[node] = true;
            num_visited += 1;
            total_cost += dist;
            // Add (cost, neighbor_node) pairs to min-heap for all unvisited neighbors
            for (int nei = 0; nei < n; ++nei) {
                if (!visited[nei]) {
                    int dist = std::abs(points[nei][0] - points[node][0]) +
                               std::abs(points[nei][1] - points[node][1]);
                    min_heap.push({dist, nei});
                }
            }
        }

        return total_cost;
    }
};
