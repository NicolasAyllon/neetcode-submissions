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
        // Map from each original node to its copy
        std::unordered_map<Node*, Node*> copies;
        Node* result = dfs(node, copies);
        return result;
    }

private:
    // Returns the deep copy of the node for the original node
    Node* dfs(Node* original, std::unordered_map<Node*, Node*>& copies) {
        // Base case:
        // A null node doesn't need any copy made.
        if (original == nullptr) 
            return nullptr;

        // A copy was already made for this original, return it.
        if (copies.find(original) != copies.end())
            return copies[original];

        // Recursive case:
        //   It must be true that if (copies.find(original) == copies.end())
        //     -> This original doesn't have a copy yet.
        //
        // Make a copy of this node, insert it in the map,
        // and recursively add copies of all its neighbors
        // to its neighbors list.
        Node* copy = new Node(original->val);
        copies[original] = copy;
        for (Node* neighbor : original->neighbors) {
            Node* copyOfNeighbor = dfs(neighbor, copies);
            copies[original]->neighbors.push_back(copyOfNeighbor);
        }
        return copy;
    }
};
