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
    // Approach: Do it without a hashmap.
    // Iterate through the list creating a deep copy for each node and inserting it after the original.
    // For example if the original was:
    // A -> B -> C -> ... -> Z -> nullptr
    // Then creating all the deep copies and inserting them would give:
    // A -> A' -> B -> B' -> C -> C -> ... -> Z -> Z' -> nullptr
    // Then we split the lists and return the head of the deep copy:
    // A -> B -> C -> ... -> Z -> nullptr
    // A' -> B' -> C' -> ... -> Z' -> nullptr (head A' is returned)
    Node* copyRandomList(Node* head) {
        // If the original list is empty, no copies needed
        if (head == nullptr) 
            return nullptr;


        Node* cur = head;
        // Pass 1: create deep copies and insert them after the original
        // This fills the 'val' field of the copied nodes, but we still need to fill in 'next' and 'random'
        while (cur != nullptr) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        // Pass 2: fill in 'next' of each deep copy
        cur = head;
        while (cur != nullptr) {
            // Since each original node is immediately follwed by its deep copy, we can get the coorresponding node
            // for the 'random' field as 'random->next'
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            } 
            cur = cur->next->next;
        }
        // Pass 3: split the lists
        cur = head;
        Node* copyHead = head->next;
        while (cur != nullptr) {
            Node* copy = cur->next;
            cur->next = copy->next;
            // If there is an original node following the copy (i.e. this isn't the last node in the list)
            // then set the copy's next to skip over it.
            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }
            cur = cur->next;
        }
        return copyHead;
    }
};
