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
    // Recursive approach:
    // We define the first node in the merged list.
    // After this node, what follows is the result of merging two lists:
    // - the list whose head is the node after the one we picked.
    // - the list whose head is the same because we didn't pick it for the first node in the merged list
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If one list is empty return the other
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        // We know both lists are not empty, so we find the first node in the merged list
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else { // list1->val > list2->val
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
