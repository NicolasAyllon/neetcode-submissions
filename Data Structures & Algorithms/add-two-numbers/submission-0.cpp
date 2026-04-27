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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Iterate through both lists at once
        // and build the resulting list.
        ListNode* placeholder_head = new ListNode();
        ListNode* tail = placeholder_head;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int carry = 0;

        while (cur1 != nullptr || cur2 != nullptr || carry > 0) {
            // Examine the digit at this placevalue
            int val1 = (cur1 ? cur1->val : 0);
            int val2 = (cur2 ? cur2->val : 0);
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            carry = sum / 10;

            // Create new ListNode and append to the end;
            ListNode* node = new ListNode (digit);
            tail->next = node;

            // Advance tail, cur1, cur2
            tail = node;
            if (cur1) cur1 = cur1->next;
            if (cur2) cur2 = cur2->next;
        }
        // If there is a nonzero carry, add it as the last node.
        ListNode* result = placeholder_head->next;
        delete placeholder_head;
        return result;
    }
};
