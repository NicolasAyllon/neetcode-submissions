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
        // Create a hash set to track which nodes we've visited
        std::unordered_set<ListNode*> visited;
        
        // Traverse the list until we reach the end or a node we've seen before
        ListNode* cur = head;
        while (cur != nullptr) {
            // We've seen this node before, so it's the start of a cycle
            if (visited.contains(cur)) {
                return true;
            } else { // This is the first time we've seen this ListNode* so record it in the set
                visited.insert(cur);
            }
            cur = cur->next; // Advance to next node
        }
        // We reached the end of the list, so there is no cycle
        return false;
    }
};
