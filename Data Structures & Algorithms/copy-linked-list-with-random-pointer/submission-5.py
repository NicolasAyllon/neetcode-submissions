"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    # Approach 2: Use a linked list to deep copy, without a hashmap
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # Handle empty: A list with 0 nodes has nothing to copy
        if not head:
            return None
        # Pass 1: iterate through the list and create a copy of each node
        # We insert the copy right after the original node.
        cur = head
        while cur:
            copy = Node(cur.val, next=None, random=None)
            copy.next = cur.next
            cur.next = copy
            cur = copy.next
        
        # Pass 2: Set the 'random' for each copy
        cur = head
        while cur:
            # Set he copy's (cur.next) 'random' to be the copy (.next) of cur's 'random'
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next

        # Pass 3: Split lists and return the head of the copied list
        # Input: A->A'->B->B'->C->C'...Z->Z'
        # Outputs: A->B->C->...->Z, A'->B'->C'->...->Z'
        cur = head
        copyHead = head.next
        while cur:
            copy = cur.next
            cur.next = copy.next
            # If there is a node following the copy, set the copy's next to next's copy
            if copy.next:
                copy.next = copy.next.next
            cur = cur.next

        return copyHead
        
