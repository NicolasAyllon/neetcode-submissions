"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    # Approach 1: Use a Hashmap to map nodes in the original list to the copied node
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # If the list has 0 nodes, nothing to do
        if not head:
            return None

        # 1 or more nodes
        origToCopy = {}
        origToCopy[None] = None
        # Pass 1: copy all the nodes and fill in the value
        # (Note: the 'next' and 'random' pointers will be filled in Pass 2)
        cur = head
        while cur:
            copy = Node(cur.val)
            origToCopy[cur] = copy
            cur = cur.next

        # Pass 2: fill in the 'next' and 'random' pointers of each node
        cur = head
        while cur:
            origToCopy[cur].next = origToCopy[cur.next]
            if cur.random:  
                origToCopy[cur].random = origToCopy[cur.random]
            cur = cur.next

        return origToCopy[head]
        