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
        // Empty list has no cycle
        if (head == nullptr)
            return false;

        // Create a slow and fast pointer
        ListNode* slow = head; // Advances 1 node per iteration
        ListNode* fast = head; // Advance 2 nodes per iteration

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            // If the pointers coincide, there must be a cycle
            if (slow == fast)
                return true;
        }
        // Now either fast->next == nullptr or fast->next->next == nullptr
        // So, the list has no cycle
        return false;
    }
};
