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
    ListNode* reverseList(ListNode* head) {
        // A 0- or 1-node list is equal to its reverse. Nothing to do.
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // There are 2 or more nodes.
        ListNode* cur = head;
        ListNode* ahead = head->next;
        // Terminate the reversed list by setting the original head's next to nullptr
        head->next = nullptr;
        // Reverse all interior pointers
        while (ahead != nullptr) {
            // std::cout << "cur = " << cur->val << ", ahead = " << ahead->val << '\n';
            ListNode* two_ahead = ahead->next;
            // std::cout << "\ttwo_ahead = " << (two_ahead ? two_ahead->val : -999) << '\n';
            // Instead of A->B we have A<-B
            ahead->next = cur;
            // std::cout << "\tSet ahead(" << ahead->val << ")->next = " << "cur(" << cur->val << ")" << '\n';
            // Advance
            cur = ahead;
            ahead = two_ahead;
        }
        // Since ahead is nullptr, the previous node was last in the original list,
        // and is the head of the reversed list. Return it.
        // std::cout << "The final value of cur = " << cur->val << '\n';
        return cur;
    }
};
