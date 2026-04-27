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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Let's first create a priority queue of ListNode* where we maintain the heap invariant
        // that the pointed-to value is smallest. Recall the top of the heap compares FALSE with all other elements.
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // The top of the heap is greater (>) than no other element -> Min Heap
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> minHeap;

        // Insert the head of each list into the min heap
        for (ListNode* head : lists) {
            minHeap.push(head);
        }

        // Result list using a placeholder head for ease of implementation
        ListNode placeholderHead;
        ListNode* tail = &placeholderHead; // points to the last node in the list, or to placeholderHead if empty
        
        // While there are still nodes in the heap
        while (!minHeap.empty()) {
            // Pop off smallest node and insert the next node (if any) from that list into the heap
            ListNode* node = minHeap.top();
            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
            minHeap.pop();

            // Insert the node at the end of the list and update tail
            tail->next = node;
            tail = node;
        }
        // Now the heap is empty, and all k lists have been merged
        // Return the actual head of the merged list as the one after the placeholderHead
        return placeholderHead.next;
        return nullptr;
    }
};
