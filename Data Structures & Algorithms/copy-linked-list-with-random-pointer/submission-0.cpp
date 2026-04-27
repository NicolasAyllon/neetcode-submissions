/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // An empty list's copy is also empty
        if (head == nullptr) return nullptr;

        // Map every Node* in the original list to the corresponding Node* in the copied list
        std::unordered_map<Node*, Node*> copy_map;

        // Populate the map, allocating a new corresponding node for each node in the original list
        // Right now, only fill the value.
        Node* cur = head;
        while (cur != nullptr) {
            Node* copy = new Node(cur->val);
            copy_map[cur] = copy;
            cur = cur->next;
        }

        // Iterate over the original list again, filling in the 'next' and the 'random' fields
        cur = head;
        while (cur != nullptr) {
            // Get the copy corresponding to this node, and fill in its next and random fields
            // by looking up the corresponding nodes.
            copy_map[cur]->next = copy_map[cur->next]; // Do we need to check for nullptr here?
            copy_map[cur]->random = copy_map[cur->random]; // Do we need to check for nullptr here?
            cur = cur->next;
        }
        return copy_map[head];
    }
};
