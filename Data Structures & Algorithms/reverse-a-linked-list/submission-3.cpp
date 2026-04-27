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
    // Approach 1: Iteration (not recursion)
    ListNode* reverseList(ListNode* head) {
        // A list with 0 or 1 notes is the same reversed
        if (head == nullptr || head->next == nullptr)
            return head;
            
        // Use two pointers to iterate over the list
        ListNode* cur = head;
        ListNode* ahead = head->next;

        while (ahead != nullptr) {
            // Set ahead's next to point back to cur
            ListNode* twoAhead = ahead->next;
            ahead->next = cur;
            cur = ahead;
            ahead = twoAhead; 
        }

        // Finally set the original head (new tail) to have no next node.
        head->next = nullptr;
        
        // Since ahead == nullptr, cur is the tail (last node)
        return cur;
    }
};
