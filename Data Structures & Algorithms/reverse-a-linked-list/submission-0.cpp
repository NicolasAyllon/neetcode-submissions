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
    ListNode* reverseList(ListNode* head) {
        // There are 0 or 1 nodes. Nothing to do.
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // There are 2 or more nodes
        // The original list is:
        // head -> node1 -> node2 -> ... -> tail -> nullptr
        // Let's assume that this function correctly returns the head of the reversed list.
        ListNode* head_of_reversed_list = reverseList(head->next);

        // The node that followed this one, should have its 'next' pointer point back to this node.
        // Since this node was the head of a list, after reversal, it's next pointer will point to nothing
        head->next->next = head;
        head->next = nullptr;

        return head_of_reversed_list;
    }
};
