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
    // Approach 2: Recursion
    ListNode* reverseList(ListNode* head) {
        // Base case: We reverse a list of length 0 or 1.
        if (head == nullptr || head->next == nullptr)
            return head;

        // We have a list of length 2 or more
        ListNode* newHead = reverseList(head->next);

        // Set the next node's next to point back to this one
        head->next->next = head;

        // Set this node's next to nullptr since it's the new tail (right now)
        // Note: we'll overwrite this in the previous stack frame with the line head->next->next = head
        // If this 'head' was not the head of the original list.
        head->next = nullptr;

        // Return the new head
        return newHead;
    }
};
