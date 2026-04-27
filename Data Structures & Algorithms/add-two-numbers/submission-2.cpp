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
        // Iterate through the numbers from ones digit (head) 
        // to the most significant digit (tail)
        // While there are two digits to add:
        ListNode placeholder_head(0);
        ListNode* tail = &placeholder_head;
        int carry = 0;
        while (l1 || l2) {
            // Get the sum's ones digit and tens digit
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            int result_digit = sum % 10;
            carry = sum / 10;

            // Append the digit to the result
            tail->next = new ListNode(result_digit, nullptr);

            // Advance tail, l1 and l2
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
            tail = tail->next;
        }
        // Now l1 and l2 are nullptr
        // Append a carry if nonzero
        if (carry > 0) {
            tail->next = new ListNode(carry, nullptr);
            tail = tail->next;
        }

        return placeholder_head.next;
    }
};
