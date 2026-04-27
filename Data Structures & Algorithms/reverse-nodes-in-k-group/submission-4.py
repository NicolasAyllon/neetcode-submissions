# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Count to see how many nodes there are
        cur = head
        length = 0
        while cur and length < k:
            length += 1
            cur = cur.next

        # If there are less than k, return the head of the original list (don't reverse it)
        if length < k:
            return head

        # There are at least k nodes, so reverse the first k, and recursively call reverseKGroup
        # to reverse the rest of the list after this K-group
        cur = head
        ahead = cur.next
        for i in range(k - 1): # Since ahead starts at the 2nd node, we'll actually need k - 1 iterations, not k
            two_ahead = ahead.next
            ahead.next = cur
            cur = ahead
            ahead = two_ahead
        
        # Now cur has advanced k - 1 nodes to be the last node in the K-group, and 'ahead' is the first node after this K-group
        head_of_reversed_k_group = cur

        # The tail of the reversed K-group was the original 'head', so its 'next' will have to point to the result
        # of reversing all K-groups after this one. The first node after this K-group is 'ahead'
        head.next = self.reverseKGroup(ahead, k)
        return head_of_reversed_k_group


        