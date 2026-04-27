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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Use two pointers advancing in tandem.
        // When the first pointer reaches the end (nullptr)
        // The other pointer should be at the node before the one to delete
        
        // For ease of implementation add a node before the head
        ListNode placeholder_head(0, head);
        ListNode* cur = &placeholder_head;
        ListNode* ahead = &placeholder_head;
        // We want cur to stop at the node before the one we'll delete
        // So if cur->next points to the nth-from-last node, then ahead->next is nullptr.
        // We impose that the distance between cur and ahead is n

        // Give ahead a headstart of n nodes
        for (int i = 0; i < n; ++i) {
            ahead = ahead->next;
        }
        // Advance both in tandem until ahead is on the last node
        while (ahead->next != nullptr) {
            ahead = ahead->next;
            cur = cur->next;
        }
        // Now ahead->next == nullptr and cur->next is the nth-from-last node that we'll delete
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        return placeholder_head.next;
    }
};
