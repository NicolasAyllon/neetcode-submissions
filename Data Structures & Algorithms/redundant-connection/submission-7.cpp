class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Track the component index of each node: 0, 1, 2, ..., n-1, n
        // We'll leave index 0 unused to match the 1-based indexing in edges
        const int n = edges.size();
        std::vector<int> cc(n+1);
        // In a union-find data structure. Initially each node's parent is itself.
        for (int i = 0; i <= n; ++i) {
            cc[i] = i;
        }

        // Iterate through the edges of the graph.
        // Since we want 
        for (const auto& edge : edges) {
            int a = edge.at(0);
            int b = edge.at(1);

            // If both nodes have the same parent, then they belong to the same connected component
            int root_a = findRoot(a, cc);
            std::cout << "After findRoot(a):" << '\n'; // DEBUG
            for (int node : cc) { std::cout << node << " "; } std::cout << '\n'; // DEBUG
            

            int root_b = findRoot(b, cc);
            std::cout << "After findRoot(b):" << '\n'; // DEBUG
            for (int node : cc) { std::cout << node << " "; } std::cout << '\n'; // DEBUG

            // Therefore the edge (a, b) is redundant. Return it!
            if (root_a == root_b) {
                std::cout << "Node " << a << " and " << b << " both have root " << root_a << '\n';
                return edge;
            }
            // The two nodes were in different components, but now place them in the same component.
            // Set the root of b's component to have a's root as a parent. (Union node b with node a)
            cc.at(root_b) = root_a;
        }
        // We shouldn't reach this code, but if we do, it means that no edge was redundant. 
        // Let's return an empty edge.
        return {};
    }

private:
    // Return the node that serves as the root component for the node that was passed in.
    // The root is identified by the fact that cc[root_node] = root_node;
    int findRoot(int node, std::vector<int>& cc) {
        // Base case: node is the root.
        if (node == cc.at(node)) return node;

        // Recursive case:
        // Find the root component of this node's parent.
        // Path compression:
        // - update cc array so that cc[node] points directly to the root of this component
        cc.at(node) = findRoot(cc[node], cc);
        return cc.at(node);
    }
};
