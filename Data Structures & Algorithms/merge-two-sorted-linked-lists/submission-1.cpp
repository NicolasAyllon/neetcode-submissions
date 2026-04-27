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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Using a temporary node that comes before the head simplifies the implemenation
        ListNode placeholder_head(0, nullptr);

        ListNode* tail = &placeholder_head; // tail of merged list
        ListNode* cur1 = list1; // current node of list1
        ListNode* cur2 = list2; // current node of list2

        while (cur1 != nullptr && cur2 != nullptr) {
            // Append the node with the smaller value to the merged list, prefer list1 in case of ties
            if (cur1->val <= cur2->val) {
                tail->next = cur1;
                cur1 = cur1->next;
            } else { // cur1->val > cur2->val
                tail->next = cur2;
                cur2 = cur2->next;
            }
            tail = tail->next;
        }

        // Now at least one list has no nodes left
        // If list1 is empty, append the rest of list2.
        // Note this works even if the other list has no more nodes (nullptr) to be the 'next' field
        if (cur1 == nullptr) {
            tail->next = cur2;
        }
        if (cur2 == nullptr) {
            tail->next = cur1;
        }
        // Finally return the head of the merged list
        return placeholder_head.next;
    }
};
