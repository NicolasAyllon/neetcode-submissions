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
            std::cout << "There are " << lists.size() << " lists. Merging in pairs...\n";
            // Iterate through the list of lists, merging lists in pairs.
            for (auto it = lists.begin(); it != lists.end();) {
                ListNode* l1 = *it;
                ListNode* l2 = it + 1 != lists.end() ? *(it + 1) : nullptr;
                *it = mergeLists(l1, l2);

                std::cout << "After merge: " << listToString(*it) << '\n';

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
        std::cout << "l1 = " << listToString(l1) << '\n';
        std::cout << "l2 = " << listToString(l2) << '\n';
        // ListNode* placeholder_head = new ListNode();
        ListNode* placeholder_head = (ListNode*) alloca(sizeof(ListNode));
        ListNode* cur = placeholder_head;
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
        
        // No need to delete/deallocate the placeholder since it's on the stack (alloca).
        return placeholder_head->next;
    }

    // Print the list on 1 line as values, ended by a newline.
    std::string listToString(ListNode* node) {
        if (node == nullptr) return "[ ]";
        // Use stringstream to build the string
        std::stringstream ss;
        ss << "[ ";
        // Print the first value
        if (node != nullptr)
            ss << node->val;
        // Print the rest of the values
        while ((node = node->next) != nullptr) {
            ss << " -> " << node->val;
        }
        ss << " ]";
        return ss.str();
    }
};
