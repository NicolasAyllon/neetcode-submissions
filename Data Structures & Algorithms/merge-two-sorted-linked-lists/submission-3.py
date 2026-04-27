# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    # Iterative approach
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        placeholder_head = ListNode(val=0, next=None)
        tail = placeholder_head # tail of merged list
        
        # While both lists have nodes, append the smaller one to the end of the merged list
        while list1 and list2:
            if list1.val <= list2.val:
                tail.next = list1
                list1 = list1.next
            else: # list1.val > list2.val
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        # Now at least one of the lists has no more nodes (list1 == None or list2 == None)
        if list1:
            tail.next = list1
        else: # list1 == None
            tail.next = list2

        # Return the node after the placeholder, which is the true head of the merged list
        return placeholder_head.next 
        