/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Use a hashmap to map nodes in the original graph to their deep copies
        std::unordered_map<Node*, Node*> copies;
        dfs(node, copies);
        return copies[node];
    }

private:
    // Returns the deep copies of this node in the cloned graph.
    // Note: the deep copies's neighbors are already connected to their deep copies
    Node* dfs(Node* node, std::unordered_map<Node*, Node*>& copies) {
        // Base cases:
        // The deep copy of a null node is also a null node
        if (node == nullptr) return nullptr;
        // If this node already has a deep copy, return it
        if (copies.contains(node)) {
            return copies[node];
        }
        // Recursive case:
        // This node doesn't yet have a deep copy, so make one
        copies[node] = new Node(node->val);
        // Connect it to the deep copies of all its neighbors
        for (Node* neighbor : node->neighbors) {
            Node* neighborCopy = dfs(neighbor, copies);
            copies[node]->neighbors.push_back(neighborCopy);
        }
        // Finally return the deep copy
        return copies[node];
    }
};
