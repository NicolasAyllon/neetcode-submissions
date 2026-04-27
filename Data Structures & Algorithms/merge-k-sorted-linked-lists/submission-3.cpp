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

// Idea:
// Repeatedly merge lists in pairs. For example:
// Merge 8 lists into 4, then 4->2, then 2->1.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Handle edge cases:
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            // Iterate through the list of lists, merging lists in pairs.
            for (auto it = lists.begin(); it != lists.end();) {
                ListNode* l1 = *it;
                ListNode* l2 = it + 1 != lists.end() ? *(it + 1) : nullptr;
                *it = mergeLists(l1, l2);

                if (it + 1 != lists.end())
                    it = lists.erase(it + 1);
                else // it + 1 == lists.end()
                    it = lists.end();
            }
        }
        return lists.front();
    }

    // Merge all nodes from l1 and l2 into a new lists and return its head.
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        // ListNode* placeholder_head = new ListNode();
        ListNode stack_allocated_placeholder_head;
        ListNode* cur = &stack_allocated_placeholder_head;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        // Both lists have nodes. Compare and append the smaller to the result.
        while (node1 != nullptr && node2 != nullptr) {
            // Node 1 is smaller, append to result list and advance.
            if (node1->val <= node2->val) {
                cur->next = node1;
                cur = cur->next;
                node1 = node1->next;
            } 
            // Node 2 is smaller, append to result list and advance.
            else {
                cur->next = node2;
                cur = cur->next;
                node2 = node2->next;
            }
        }

        // One of the lists has run out of nodes, append any remaining nodes
        if (node1 != nullptr)
            cur->next = node1;

        if (node2 != nullptr)
            cur->next = node2;
        
        // Save the first real node after the placeholder as the result.
        // Clean up the placeholder and return the result.
        ListNode* result = stack_allocated_placeholder_head.next;
        // delete placeholder_head;
        return result;
    }
};
