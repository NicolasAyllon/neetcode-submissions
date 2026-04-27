class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Let's consider all possible edges from (xi, yi)->(xj, yj) with cost |xi - xj| + |yi - yj|
        // Add all possible edges to a list, then sort it by cost.
        // For brevity, use the index of the points instead of the coordinates.
        std::vector<std::tuple<int, int, int>> edges;
        const int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = std::abs(points[j][0] - points[i][0]) + std::abs(points[j][1] - points[i][1]);
                edges.push_back({dist, i, j});
            }
        }
        // Sort edges by Manhattan distance (element 0 of tuple)
        std::sort(edges.begin(), edges.end(), [] (const auto& a, const auto& b) {
            return std::get<0>(a) < std::get<0>(b);
        });

        // // Print sorted list for debugging
        // for (const auto& edge : edges) {
        //     int dist = std::get<0>(edge);
        //     int i = std::get<1>(edge);
        //     int j = std::get<2>(edge);
        //     std::cout << "edge: dist = " << dist << ", i = " << i << ", j = " << j << '\n';
        // }


        // Create Union-Find data structure ("cc" = connected component)
        // with each node's parent as itself.
        std::vector<int> cc(n);
        for (int i = 0; i < n; ++i) { cc[i] = i; }
        // Each group has an initial size of 1.
        std::vector<int> cc_sizes(n, 1);

        // Kruskal's algorithm for a minimum spannning tree (MST).
        int num_ccs = n;
        int total_cost = 0;
        for (const auto& edge : edges) {
            // Extract parts of edge tuple (we need std::tie to do it without structured bindings)
            int dist, i, j;
            std::tie(dist, i, j) = edge;

            // If points i and j are already connected, continue
            if (findRootComponent(cc, i) == findRootComponent(cc, j)) continue;

            // Otherwise, add edge (i, j) to Union-Find and increment cost.
            joinComponents(cc, cc_sizes, i, j);
            total_cost += dist;

            if (--num_ccs == 1) break;
        }
        // Temporarily add needed return value
        return total_cost;
    }

private:
    // Helping functions for Union-Find
    // TODO: implement path compression...
    int findRootComponent(const std::vector<int>& cc, int i) {
        // Traverse up to parent nodes until we reach the top (root component)
        while (cc[i] != i) {
            i = cc[i];
        }
        return i;
    }

    // Union by rank and update sizes
    void joinComponents(std::vector<int>& cc, std::vector<int>& cc_sizes, int i, int j) {
        // Get root components of both nodes
        int root_i = findRootComponent(cc, i);
        int root_j = findRootComponent(cc, j);
        // Point the root of the smaller tree to the root of the larger one, and update size of parent.
        if (cc_sizes[root_i] < cc_sizes[root_j]) {
            cc[root_i] = root_j;
            cc_sizes[root_j] += cc_sizes[root_i];
        } else {
            cc[root_j] = root_i;
            cc_sizes[root_i] += cc_sizes[root_j];
        }
    }
};
