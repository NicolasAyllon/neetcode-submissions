# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    # Recursive Approach
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # If one of the lists is empty, return the other one
        if not list1:
            return list2
        if not list2:
            return list1

        # Both lists are not empty, so the head of the merged list
        # will be the smaller of the two nodes at the heads of list1 and list2
        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else: # list1.val > list2.val
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2
        