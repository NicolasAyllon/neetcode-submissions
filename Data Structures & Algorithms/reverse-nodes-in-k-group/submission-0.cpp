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
        // Handle empty list or invalid k
        if (head == nullptr || k <= 0) return nullptr;

        // Recursive approach:
        // See if we can advance k nodes.
        // Note that the desired list is can be expressed recursively as:
        // (reverse_k_group[0, len] = first->...reversed[0, k]...->last -> reverse_k_group[k, len]
        // And note first was originally the last node of the group; last was the first.
        ListNode* cur = head;
        int count = 0;
        while (cur != nullptr && count < k) {
            cur = cur->next;
            count++;
        }
        // We advanced k nodes
        if (count == k) {
            // Assign 'cur' the new head of the list that results from k-reversal of the list at cur.
            cur = reverseKGroup(cur, k);
            // Assuming the Recursive Leap of Faith, we can now iterate through this group and reverse the pointers.
            while (count--) {
                // Initially, current is the head of the k-reversal of the rest of the list.
                // What was originally the first node, will become the last, so it's 'next' pointer should be to 'cur'
                ListNode* tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
            }
            // After this group of k nodes is reversed, the last one ('cur') will the head.
            head = cur;
        }
        return head;
    }
};
