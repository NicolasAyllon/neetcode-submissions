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
    // Consider case odd
    // 1 -> 2 -> 3 -> 4 -> 5. Want slow = 3, fast = nullptr
    // l1 = 1 -> 2
    // l2 = 3 -> 4 -> 5
    // l2_rev = 5 -> 4 -> 3
    // Alternating merge l1 and l2_rev yields the desired reordering.
    // 1 -> 5 -> 2 -> 4 -> 3

    // For case even:
    // 1 -> 2 -> 3 -> 4. Want slow = 2, fast = 4
    // ...
    // Alternating merge l1 and l2_rev yields the desired reordering.
    // 1 -> 4 -> 2 -> 3

    void reorderList(ListNode* head) {
        // If the list has 0 or 1 nodes, nothing to do
        if (head == nullptr || head->next == nullptr)
            return;

        // Calculate midpoint of list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        // Now fast is either the last node (even number of nodes) or nullptr (odd number of nodes)
        // And slow is the tail of the first list, so slow->next is the head of the second list
        ListNode* l2 = slow->next; // Define head of second list
        slow->next = nullptr; // Split the original list by terminating the first one with nullptr
        printList(l2);
        // Reverse the list
        ListNode* l2_reversed = reverse(l2);
        printList(l2_reversed);

        ListNode* result = alternatingMerge(l1, l2_reversed);
    }

private:
    // Merges the two lists in an alternating fashion
    // Start with l1, then l2, then l1, then l2, ...
    ListNode* alternatingMerge(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* merged_tail = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;

            l1->next = l2;
            l2->next = l1_next;
            merged_tail = l2;

            l1 = l1_next;
            l2 = l2_next;
        }
        // Now at least one list is nullptr
        if (l1 != nullptr) {
            merged_tail->next = l1;
        } else { // l1 == nullptr
            merged_tail->next = l2; // also correct if l2 == nullptr
        }
        return head;
    }

    // Reverses the list with this node as the head
    // and returns the head of the reversed list
    ListNode* reverse(ListNode* head) {
        // A list of 0 or 1 nodes is the same reversed
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // Otherwise, reverse the rest of the list recursively
        ListNode* head_of_reversed_list = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        // Return the head of the reversed list
        return head_of_reversed_list;
    }

    void printList(ListNode* head) {
        if (head == nullptr) {
            std::cout << "[]";
            return;
        }
        std::cout << "[";
        // Print first
        std::cout << head->val;
        head = head->next;
        // Print the rest
        while (head) {
            std::cout << " -> " << head->val;
            head = head->next;
        }
        std::cout << "]\n";
    }
};
