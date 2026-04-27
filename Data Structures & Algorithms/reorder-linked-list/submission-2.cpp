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
    // Redo the solution without any helping methods/functions
    void reorderList(ListNode* head) {
        // A list with 0 or 1 nodes can't be reordered
        if (head == nullptr || head->next == nullptr)
            return;

        // First compute the midpoint of the list using a pair of slow and fast pointers
        ListNode* slow = head; // Node 1 (1-based index)
        ListNode* fast = head->next; // Node 2 (1-based index)
        // Advance both until fast is either the tail (even nodes), or nullptr (odd nodes)
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now if there were i iterations, then slow = 1 + i, fast = 2 + 2i
        // We'll take slow to be the tail of the first half list
        // So slow->next is the head of the second half list
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Reverse the second half
        ListNode* prev = nullptr;
        while (second != nullptr) {
            ListNode* second_next = second->next;
            second->next = prev;
            prev = second;
            second = second_next;
        }
        // Now second == nullptr, so prev is the head of the reversed list

        // Merge the lists with heads first and prev (head of reversed second half, renamed second). 
        // The second list is equal or shorter than the first, so we only need to check
        ListNode* first = head;
        second = prev;
        while (second != nullptr) {
            ListNode* first_next = first->next;
            ListNode* second_next = second->next;
            first->next = second;
            second->next = first_next;
            first = first_next;
            second = second_next;
        }
        // Now second == nullptr, but it's possible first != nullptr, 
        // in which case it's the last node of the merged list
    }
};
