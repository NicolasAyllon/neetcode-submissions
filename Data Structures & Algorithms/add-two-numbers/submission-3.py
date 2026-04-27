# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # While either node is not null, iterate through digit by digit
        # from ones to tens, to hundreds, and so on, until both lists run out of nodes (digits)
        placeholder_head = ListNode() 
        # To make implementation easier, create a node before the first digit.
        # We we need to return the head of the actual result list, we'll return placeholder.next
        tail = placeholder_head
        carry = 0
        while l1 or l2:
            d1 = l1.val if l1 else 0
            d2 = l2.val if l2 else 0
            sum = d1 + d2 + carry
            digit = sum % 10
            carry = sum // 10
            # Append the node for the next digit in the result
            tail.next = ListNode(digit)
            # Advance l1, l2 (if possible)
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            # Always advance the tail since we know there is a next node
            tail = tail.next
        
        # Now both l1 and l2 are None
        # So append any remaining carry
        if carry > 0:
            tail.next = ListNode(carry)
            tail = tail.next
        # Return the head of the result, which the node after the placeholder_head
        return placeholder_head.next
