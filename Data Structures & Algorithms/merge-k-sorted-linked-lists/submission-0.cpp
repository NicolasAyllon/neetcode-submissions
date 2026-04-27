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
    // We will empty all the lists so that after this function is called,
    // every list in 'lists' will be empty.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* placeholder_head = new ListNode();
        ListNode* last = placeholder_head;
        // To make merging fast, we'd like to be able to find
        // the smallest element from the lists in constant (O(1)) time.
        // So, we should use a heap. Recall, for a min heap:
        // - comparator Comp(a, b) returns true if a comes before b.
        // - the "last" item is at the top of the heap, like:
        // - child_1 < child_2 < ... < child_n < top_of_heap
        auto cmp = [](ListNode* heap_child, ListNode* heap_parent) {
            return heap_child->val > heap_parent->val;
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> min_heap(cmp);
        // Add the first node from each list into the heap.
        for (const auto& front : lists) {
            min_heap.push(front);
        }
        // While heap is not empty, remove the smallest element (at the top)
        while (!min_heap.empty()) {
            ListNode* node = min_heap.top();
            min_heap.pop();
            // Add this node to the end of the result list
            last->next = node;
            last = node;
            // Push the node that came after this one (in its list) into the heap.
            if (node->next != nullptr)
                min_heap.push(node->next);
        }
        
        // Save the result, and deallocate the placeholder head (sentinel head)
        ListNode* first = placeholder_head->next;
        delete placeholder_head;
        return first;
    }
};
