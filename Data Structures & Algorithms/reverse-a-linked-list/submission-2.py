# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Observe that the original list has HEAD=head
        #   head -> node1 -> node2 -> ... -> tail -> None
        # We want the reversed list
        #   None <- head <- node1 <- node2 <- ... <- tail which has HEAD=tail
        
        # A list with 0 or 1 elements is the same reversed
        if not head or not head.next:
            return head

        # List has 2 or more elements
        cur = head
        ahead = cur.next
        while ahead:
            twoAhead = ahead.next
            ahead.next = cur
            cur = ahead
            ahead = twoAhead

        # Now ahead == None, so cur is the tail of the original list, or the head of the new list
        # The original head is now the tail, so set it's 'next' to None
        head.next = None
        return cur