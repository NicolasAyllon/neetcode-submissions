/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*> visited = {};
        ListNode* current = head;
        while (current != nullptr) {
            // If we've seen this node before, there's a cycle.
            if (visited.count(current) > 0) {
                return true;
            }
            // Insert the node
            visited.insert(current);
            current = current->next;
        }
        return false;
    }
};
