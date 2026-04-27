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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Are there at least k nodes? Count them.
        ListNode* cur = head;
        int length = 0;
        while (cur != nullptr && length < k) {
            length++;
            cur = cur->next;
        }

        // If less than k nodes, return the original list's head
        if (length < k) return head;

        // Otherwise, reverse the first k and make a recursive call
        // to reverse the remaining K-groups after this one.
        cur = head;
        ListNode* ahead = cur->next;
        for (int i = 0; i < k-1; ++i) {
            ListNode* two_ahead = ahead->next;
            ahead->next = cur;
            cur = ahead;
            ahead = two_ahead;
        }
        // The last node of the K-group is 'cur'
        ListNode* reversed_k_group_head = cur;

        // The original head is now the tail of the K-group, so we should set its 'next' to be the result
        // of reversing nodes in K-groups after this group of K. And the node after this K-group is 'ahead'

        head->next = reverseKGroup(ahead, k);
        // Finally return the head of the reversed K-group, which is 'cur'
        return reversed_k_group_head;
    }

};
