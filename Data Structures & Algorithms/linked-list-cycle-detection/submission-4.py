# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # Approach: Traverse list, using a hash set to keep track
        # of the node's we've seen. If we ever come to a node we've already seen
        # then there must be a cycle
        visited = set()
        cur = head
        while cur:
            if cur in visited:
                return True
            else:
                visited.add(cur)
            cur = cur.next
        # cur == None means we reached the end of the list, so there were no cycles
        return False

        